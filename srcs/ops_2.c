/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:24:19 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/21 19:24:20 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ra(struct s_stack *a, struct s_stack *b)
{
	struct s_snode *tmp1;
	struct s_snode *tmp2;

	if (a->size >= 2)
	{
		tmp1 = a->top;
		tmp2 = a->top;
		while (tmp2->next)
			tmp2 = tmp2->next;
		a->top = a->top->next;
		tmp1->next = NULL;
		tmp2->next = tmp1;
		tmp1->delta = 1;
	}
	(void)b;
}

void			rb(struct s_stack *a, struct s_stack *b)
{
	struct s_snode *tmp1;
	struct s_snode *tmp2;

	if (b->size >= 2)
	{
		tmp1 = b->top;
		tmp2 = b->top;
		while (tmp2->next)
			tmp2 = tmp2->next;
		b->top = b->top->next;
		tmp1->next = NULL;
		tmp2->next = tmp1;
		tmp1->delta = 1;
	}
	(void)a;
}

void			rr(struct s_stack *a, struct s_stack *b)
{
	ra(a, b);
	rb(a, b);
}
