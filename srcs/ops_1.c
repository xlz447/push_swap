/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:24:24 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/21 19:24:37 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			sa(struct s_stack *a, struct s_stack *b)
{
	int *tmp;

	if (a->size >= 2)
	{
		tmp = a->top->content;
		a->top->content = a->top->next->content;
		a->top->next->content = tmp;
		a->top->delta = 1;
		a->top->next->delta = 1;
	}
	(void)b;
}

void			sb(struct s_stack *a, struct s_stack *b)
{
	int *tmp;

	if (b->size >= 2)
	{
		tmp = b->top->content;
		b->top->content = b->top->next->content;
		b->top->next->content = tmp;
		b->top->delta = 1;
		b->top->next->delta = 1;
	}
	(void)a;
}

void			ss(struct s_stack *a, struct s_stack *b)
{
	sa(a, b);
	sb(a, b);
}

void			pa(struct s_stack *a, struct s_stack *b)
{
	int tmp_index;

	if (b->size)
	{
		tmp_index = b->top->index;
		push(a, pop(b));
		a->top->delta = 1;
		a->top->index = tmp_index;
	}
}

void			pb(struct s_stack *a, struct s_stack *b)
{
	int tmp_index;

	if (a->size)
	{
		tmp_index = a->top->index;
		push(b, pop(a));
		b->top->delta = 1;
		b->top->index = tmp_index;
	}
}
