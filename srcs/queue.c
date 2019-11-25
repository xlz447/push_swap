/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:57:24 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/19 17:57:26 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

struct s_queue	*initq(void)
{
	struct s_queue *out;

	if (NULL == (out = malloc(sizeof(struct s_queue))))
		return (NULL);
	out->first = NULL;
	out->last = NULL;
	out->size = 0;
	return (out);
}

int				enqueue(struct s_queue *queue, char *content)
{
	struct s_qnode *add;

	if (NULL == (add = malloc(sizeof(struct s_qnode))))
		return (-1);
	add->content = content;
	add->next = NULL;
	if (queue->first == NULL || queue->last == NULL)
	{
		queue->first = add;
		queue->last = add;
	}
	else
	{
		queue->last->next = add;
		queue->last = add;
	}
	queue->size++;
	return (0);
}

char			*dequeue(struct s_queue *queue)
{
	char			*out;
	struct s_qnode	*tmp;

	if (!queue || !queue->first || !queue->last)
		return (NULL);
	if (queue->first == queue->last)
	{
		out = queue->first->content;
		free(queue->first);
		queue->first = NULL;
		queue->last = NULL;
		return (out);
	}
	out = queue->first->content;
	tmp = queue->first;
	queue->first = queue->first->next;
	free(tmp);
	queue->size--;
	return (out);
}

char			*peekq(struct s_queue *queue)
{
	if (!queue || !queue->first || !queue->last)
		return (NULL);
	return (queue->first->content);
}

void			print_color(int c, struct s_snode *an, struct s_snode *bn)
{
	char			*a;
	char			*b;

	a = (an) ? ft_itoa(*an->content) : ft_strnew(0);
	b = (bn) ? ft_itoa(*bn->content) : ft_strnew(0);
	if (c)
	{
		if (an && an->delta)
			ft_printf("{cyan}%*s{noc}", (ft_strlen(a) + 11) / 2, a);
		else
			ft_printf("%*s", (ft_strlen(a) + 11) / 2, a);
		if (bn && bn->delta)
			ft_printf("{cyan}%*s\n{noc}",
				12 - ((ft_strlen(a) + 11) / 2) + (ft_strlen(b) + 11) / 2, b);
		else
			ft_printf("%*s\n",
				12 - ((ft_strlen(a) + 11) / 2) + (ft_strlen(b) + 11) / 2, b);
	}
	else
		ft_printf("%*s%*s\n", (ft_strlen(a) + 11) / 2, a,
			12 - ((ft_strlen(a) + 11) / 2) + (ft_strlen(b) + 11) / 2, b);
	free(a);
	free(b);
}
