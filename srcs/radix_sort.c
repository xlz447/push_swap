/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:32:14 by xzhu              #+#    #+#             */
/*   Updated: 2020/02/16 19:32:17 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			execute_enqueue(struct s_pushswap *p_s, char *ins)
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
	enqueue(p_s->ins, ins);
}

static void		push_group(struct s_pushswap *p_s, int dir, int *top, int *bot)
{
	struct s_stack	*origin;
	int				i;

	origin = (dir) ? p_s->a : p_s->b;
	i = origin->size;
	while (--i >= 0)
	{
		if (origin->top->group == *bot)
		{
			(dir) ? execute_enqueue(p_s, "pb") : execute_enqueue(p_s, "pa");
			(dir) ? execute_enqueue(p_s, "rb") : execute_enqueue(p_s, "ra");
		}
		else if (origin->top->group == *top)
			(dir) ? execute_enqueue(p_s, "pb") : execute_enqueue(p_s, "pa");
		else
			(dir) ? execute_enqueue(p_s, "ra") : execute_enqueue(p_s, "rb");
	}
	(*top)--;
	(*bot)++;
}

static void		update_helper(struct s_pushswap *p_s, char cur_order,
							struct s_snode *tmp, int v[3])
{
	int flips;
	int cur_flip;
	int i;

	flips = v[0];
	cur_flip = v[1];
	i = v[2];
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
		tmp->group = (i / (expo(p_s->gsize, cur_flip) / p_s->gsize))
						% p_s->gsize + 1;
	}
}

static void		update_group(struct s_pushswap *p_s, int flips, int cur_flip)
{
	struct s_snode	*tmp;
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
			tmp->group = (i / (expo(p_s->gsize, cur_flip) / p_s->gsize))
							% p_s->gsize;
			if (cur_order == '0')
				tmp->group = p_s->gsize - tmp->group - 1;
		}
		else
			update_helper(p_s, cur_order, tmp, (int[3]){flips, cur_flip, i});
		tmp = tmp->next;
	}
}

void			radix_sort(struct s_pushswap *p_s)
{
	int	flips;
	int	to_top;
	int	to_bot;
	int	cur_flip;
	int	i;

	flips = log_ceil(p_s->a->size, p_s->gsize);
	set_order_tree(p_s, flips);
	i = -1;
	cur_flip = 0;
	while (++cur_flip <= flips)
	{
		update_group(p_s, flips, cur_flip);
		to_top = (p_s->gsize == 4) ? 1 : 2;
		to_bot = to_top + 1;
		i = (p_s->gsize == 4) ? 3 : 4;
		while (--i > 0)
			push_group(p_s, (cur_flip % 2), &to_top, &to_bot);
	}
	if (p_s->b->size != 0)
		while (p_s->b->top)
			execute_enqueue(p_s, "pa");
}
