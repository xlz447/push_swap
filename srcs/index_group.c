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

static void		p_index(struct s_stack *stack)
{
	struct s_snode	*tmp;

	tmp = stack->top;
	ft_printf("\n");
	while (tmp)
	{
		ft_printf(" %d\n", tmp->index);
		tmp = tmp->next;
	}
}

void			sort_update(struct s_stack *stack)
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
	p_index(stack);
}

int				log_ceil(int n, int m)
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

void			calc_group(struct s_pushswap *p_s)
{
	double	four;
	double	five;
	int		n;

	n = p_s->a->size;
	four = 2.0 * n * log_ceil(n, 4) + n * (log_ceil(n, 4) % 2);
	five = 2.2 * n * log_ceil(n, 5) + n * (log_ceil(n, 5) % 2);
	p_s->gsize = (four < five) ? 4 : 5;
	printf("|four=%f|five=%f|\n", four, five);
	ft_printf("Group Size = %d\n", p_s->gsize);
}
