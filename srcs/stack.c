/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:10:34 by exam              #+#    #+#             */
/*   Updated: 2019/11/12 09:30:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "checker.h"

struct s_stack	*inits(void)
{
	struct s_stack *out;

	if (NULL == (out = malloc(sizeof(struct s_stack))))
		return (NULL);
	out->top = NULL;
	out->size = 0;
	return (out);
}

int				*pop(struct s_stack *stack)
{
	struct s_snode	*tmp;
	int				*out;

	if (!stack || !stack->top)
		return (NULL);
	else
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		out = tmp->content;
		free(tmp);
		stack->size--;
		return (out);
	}
}

int				push(struct s_stack *stack, int *content)
{
	struct s_snode	*new;

	if (!stack)
		return (-1);
	new = stack->top;
	while (new)
	{
		if (*new->content == *content)
			return (-1);
		new = new->next;
	}
	if (NULL == (new = malloc(sizeof(struct s_snode))))
		return (-1);
	new->content = content;
	new->next = stack->top;
	new->delta = 0;
	stack->top = new;
	stack->size++;
	return (0);
}

int				*peeks(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	else
		return (stack->top->content);
}

void			prints(struct s_checker *c_s)
{
	struct s_snode	*tmp1;
	struct s_snode	*tmp2;
	char			*a;
	char			*b;

	tmp1 = c_s->a->top;
	tmp2 = c_s->b->top;
	ft_printf("***********************\n");
	while (tmp1 || tmp2)
	{
		a = (tmp1) ? ft_itoa(*tmp1->content) : ft_strnew(0);
		b = (tmp2) ? ft_itoa(*tmp2->content) : ft_strnew(0);
		print_color(c_s->cflag, tmp1, tmp2, a, b);
		free(a);
		free(b);
		tmp1 = (tmp1) ? tmp1->next : tmp1;
		tmp2 = (tmp2) ? tmp2->next : tmp2;
	}
	ft_printf("----------- -----------\n     a           b     \n");
}
