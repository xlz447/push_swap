/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:02:44 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/19 18:02:45 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

struct			s_qnode {
	char			*content;
	struct s_qnode	*next;
};

struct			s_queue {
	struct s_qnode	*first;
	struct s_qnode	*last;
};

struct			s_snode {
	int				*content;
	struct s_snode	*next;
};

struct			s_stack {
	struct s_snode	*top;
};

struct			s_checker {
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_queue	*ins;
};

struct s_queue	*initq();
int				enqueue(struct s_queue *queue, char *content);
char			*dequeue(struct s_queue *queue);
char			*peekq(struct s_queue *queue);
int				isemptyq(struct s_queue *queue);

struct s_stack	*inits();
int				*pop(struct s_stack *stack);
int				push(struct s_stack *stack, int *content);
int				*peeks(struct s_stack *stack);
void			prints(struct s_stack *stack, char *name);

#endif
