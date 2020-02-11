
#include "push_swap.h"

int			dispatch_one(struct s_pushswap *p_s, char *ins)
{
	int		i;

	init_const_array(p_s->op_func_array, p_s->ops_array);
	i = -1;
	while (++i < 11)
	{
		if (ft_strequ(p_s->ops_array[i], ins))
		{
			p_s->op_func_array[i](p_s->a, p_s->b);
			break ;
		}
	}
	if (i == 11)
		return (-1);
	return (0);
}

int				expo(int b, int p)
{
	int		i;
	int		out;

	i = -1;
	out = 1;
	while (++i < p)
		out *= b;
	return (out);
}

void			ex_and_store_instructions(struct s_pushswap *p_s, char *ins)
{
	dispatch_one(p_s, ins);
	enqueue(p_s->ins, ins);
}

static void		put_two_groups(struct s_pushswap *p_s, int dir, int top, int bot)
{
	struct s_stack* origin;
	char			ins[3];
	int				i;

	origin = (dir) ? p_s->a : p_s->b;
	i = origin->size;
	while (--i >= 0)
	{
		if (origin->top->group == bot)
			{
				(dir) ? ft_strcpy(ins, "pb") : ft_strcpy(ins, "pa");
				ex_and_store_instructions(p_s, ins);
				(dir) ? ft_strcpy(ins, "rb") : ft_strcpy(ins, "ra");
				ex_and_store_instructions(p_s, ins);
			}
			else
			{
				if (origin->top->group == top)
					(dir) ? ft_strcpy(ins, "pb") : ft_strcpy(ins, "pa");
				else
					(dir) ? ft_strcpy(ins, "ra") : ft_strcpy(ins, "rb");
				ex_and_store_instructions(p_s, ins);
			}
	}
}

void	update_group(struct s_pushswap *p_s, int flips, int cur_flip)
{
	struct s_snode* tmp;
	int				i;
	int				n;
	char			cur_order;

	tmp = (cur_flip % 2) ? p_s->a->top : p_s->b->top;
	n = (cur_flip % 2) ? p_s->a->size : p_s->b->size;
	while (tmp)
	{
		i = (flips % 2) ? (n - tmp->index - 1) : tmp->index;
		if (cur_flip != flips)
		{
			cur_order = p_s->order[0][i / expo(p_s->gsize, cur_flip)];
			tmp->group = (i / (expo(p_s->gsize, cur_flip) / p_s->gsize)) % p_s->gsize;
			if (cur_order == '0')
				tmp->group = p_s->gsize - tmp->group - 1;
		}
		else
		{
			if (p_s->gsize == 4)
			{
				cur_order = p_s->order[flips - 1][i / expo(4, cur_flip)];
				tmp->group = (i / (expo(4, cur_flip) / 4)) % 4;
				if (cur_order == '0')
					tmp->group = 3 - tmp->group;
			}
			else
			{
				cur_order = p_s->order[0][i / expo(p_s->gsize, cur_flip)];
				tmp->group = (i / (expo(p_s->gsize, cur_flip) / p_s->gsize)) % p_s->gsize + 1;
			}
		}
		// ft_printf("tmp->index:%d group:%d\n",tmp->index, tmp->group );
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	set_order_helper(struct s_pushswap *p_s, int i, int j)
{
	if (p_s->gsize == 4)
		ft_strncpy((*(p_s->order + i) + j), "0011", 4);
	else
	{
		if (i % 2 == 0)
		{
			if (p_s->order[i + 1][j / 5] == '0')
				ft_strncpy((*(p_s->order + i) + j), "00011", 5);  //change to strcat
			else
				ft_strncpy((*(p_s->order + i) + j), "00111", 5);
		}
		else
		{
			if (p_s->order[i + 1][j / 5] == '0')
				ft_strncpy((*(p_s->order + i) + j), "11000", 5);
			else
				ft_strncpy((*(p_s->order + i) + j), "11100", 5);
		}
	}
}

void	set_order_tree(struct s_pushswap *p_s, int flips)
{
	int i;
	int j;
	int n;

	p_s->order = (char **)ft_memalloc((flips + 1) * sizeof(char *));
	p_s->order[flips] = NULL;
	if (p_s->gsize == 4)
		p_s->order[flips - 1] = ft_strdup("1100");
	else
		p_s->order[flips - 1] = ft_strdup((flips % 2) ? "00111" : "11000");
	i = flips - 2;
	n = p_s->gsize * p_s->gsize;
	while (i >= 0)
	{
		j = 0;
		p_s->order[i] = ft_strnew(n);
		while ((j < n))
		{
			set_order_helper(p_s, i, j);
			j += p_s->gsize;
		}
		i--;
		n *= p_s->gsize;
	}
}

void			radix_sort(struct s_pushswap *p_s)
{
	int	flips;
	int	to_top;
	int	to_bot;
	int	cur_flip;
	int	j;

	flips = log_ceil(p_s->a->size, p_s->gsize);
	set_order_tree(p_s, flips);
	j = -1;
	while(p_s->order[++j])
		ft_printf("%s\n", p_s->order[j]);
	cur_flip = 0;
	while (++cur_flip <= flips)
	{
		update_group(p_s, flips, cur_flip);
		to_top = (p_s->gsize == 4) ? 1 : 2;
		to_bot = to_top + 1;
		j = (p_s->gsize == 4) ? 2 : 3;
		while (j > 0)
		{
			put_two_groups(p_s, (cur_flip % 2), to_top, to_bot);
			to_top--;
			to_bot++;
			j--;
		}
	}
	if (p_s->b->size != 0)
		while (p_s->b->top)
			ex_and_store_instructions(p_s, "pa");
}