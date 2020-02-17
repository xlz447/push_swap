/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:56:35 by xzhu              #+#    #+#             */
/*   Updated: 2019/12/11 20:56:38 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_order_helper(struct s_pushswap *p_s, int i, int j)
{
	if (p_s->gsize == 4)
		ft_strcat(p_s->order[i], "0011");
	else
	{
		if (i % 2 == 0)
		{
			if (p_s->order[i + 1][j / 5] == '0')
				ft_strcat(p_s->order[i], "00011");
			else
				ft_strcat(p_s->order[i], "00111");
		}
		else
		{
			if (p_s->order[i + 1][j / 5] == '0')
				ft_strcat(p_s->order[i], "11000");
			else
				ft_strcat(p_s->order[i], "11100");
		}
	}
}

void		set_order_tree(struct s_pushswap *p_s, int flips)
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

void		sort_update(struct s_stack *stack)
{
	int				i;
	int				over;
	int				min_val;
	struct s_snode	*curr;
	struct s_snode	*min_node;

	over = -2147483648;
	i = -1;
	while (++i < (int)stack->size)
	{
		curr = stack->top;
		min_val = 2147483647;
		while (curr)
		{
			if (*curr->content < min_val && *curr->content > over)
			{
				min_val = *curr->content;
				min_node = curr;
			}
			curr = curr->next;
		}
		over = min_val;
		min_node->index = i;
	}
}

int			log_ceil(int n, int m)
{
	int		log;
	int		curr;

	log = 0;
	curr = 1;
	while (curr < n)
	{
		curr *= m;
		log++;
	}
	return (log);
}

void		calc_group(struct s_pushswap *p_s)
{
	double	four;
	double	five;
	int		n;

	n = p_s->a->size;
	four = 2.0 * n * log_ceil(n, 4) + n * (log_ceil(n, 4) % 2);
	five = 2.2 * n * log_ceil(n, 5) + n * (log_ceil(n, 5) % 2);
	p_s->gsize = (four < five) ? 4 : 5;
}
