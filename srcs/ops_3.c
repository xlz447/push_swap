/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:25:12 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/21 19:25:14 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			rra(struct s_stack *a, struct s_stack *b)
{
	struct s_snode *tmp1;
	struct s_snode *tmp2;

	if (a->size >= 2)
	{
		tmp1 = a->top;
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		tmp1->next = NULL;
		tmp2->next = a->top;
		a->top = tmp2;
		a->top->delta = 1;
	}
	(void)b;
}

void			rrb(struct s_stack *a, struct s_stack *b)
{
	struct s_snode *tmp1;
	struct s_snode *tmp2;

	if (b->size >= 2)
	{
		tmp1 = b->top;
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		tmp1->next = NULL;
		tmp2->next = b->top;
		b->top = tmp2;
		b->top->delta = 1;
	}
	(void)a;
}

void			rrr(struct s_stack *a, struct s_stack *b)
{
	rra(a, b);
	rrb(a, b);
}
