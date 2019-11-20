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
	stack->top = new;
	return (0);
}

int				*peeks(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	else
		return (stack->top->content);
}

void			prints(struct s_stack *stack, char *name)
{
	struct s_stack	*tmp;
	int				flag;

	flag = 1;
	tmp = stack;
	while (tmp->top)
	{
		if (flag == 1)
		{
			printf("%s %d", name, *tmp->top->content);
			flag = 0;
		}
		else
			printf(" %d", *tmp->top->content);
		tmp->top = tmp->top->next;
	}
	printf("\n");
}
