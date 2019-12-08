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

void			clear_stack(struct s_stack *stack)
{
	void	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = (void*)pop(stack);
		free(tmp);
	}
	free(stack);
}
