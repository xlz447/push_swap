/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:52:57 by xzhu              #+#    #+#             */
/*   Updated: 2020/02/17 16:53:01 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(struct s_stack *a, int to_find)
{
	struct s_snode	*tmp;
	int				out;

	tmp = a->top;
	out = 0;
	while (tmp->index != to_find)
	{
		tmp = tmp->next;
		out++;
	}
	return (out);
}

static void	sort_three(struct s_pushswap *p_s, int start)
{
	if (p_s->a->top->index < p_s->a->top->next->index)
		execute_enqueue(p_s, "rra");
	if (p_s->a->top->index == 2 + start)
		execute_enqueue(p_s, "ra");
	if (p_s->a->top->index == 1 + start)
		execute_enqueue(p_s, "sa");
}

static void	sort_four(struct s_pushswap *p_s, int start)
{
	if (find_index(p_s->a, start) > 1)
		while (p_s->a->top->index != start)
			execute_enqueue(p_s, "rra");
	else
		while (p_s->a->top->index != start)
			execute_enqueue(p_s, "ra");
	execute_enqueue(p_s, "pb");
	sort_three(p_s, 1 + start);
	execute_enqueue(p_s, "pa");
}

static void	sort_five(struct s_pushswap *p_s)
{
	if (find_index(p_s->a, 0) > 2)
		while (p_s->a->top->index != 0)
			execute_enqueue(p_s, "rra");
	else
		while (p_s->a->top->index != 0)
			execute_enqueue(p_s, "ra");
	execute_enqueue(p_s, "pb");
	sort_four(p_s, 1);
	execute_enqueue(p_s, "pa");
}

void		sort_small(struct s_pushswap *p_s)
{
	if (p_s->a->size == 2)
		execute_enqueue(p_s, "sa");
	else if (p_s->a->size == 3)
		sort_three(p_s, 0);
	else if (p_s->a->size == 4)
		sort_four(p_s, 0);
	else if (p_s->a->size == 5)
		sort_five(p_s);
}
