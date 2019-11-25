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

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

struct			s_qnode {
	char			*content;
	struct s_qnode	*next;
};

struct			s_queue {
	struct s_qnode	*first;
	struct s_qnode	*last;
	unsigned		size;
};

struct			s_snode {
	int				*content;
	int				delta;
	struct s_snode	*next;
};

struct			s_stack {
	struct s_snode	*top;
	unsigned		size;
};

typedef	void	t_op_function(struct s_stack *a, struct s_stack *b);

struct			s_checker {
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_queue	*ins;
	int				vflag;
	int				cflag;
	t_op_function	*op_func_array[11];
	char			*ops_array[11];
};

struct s_queue	*initq();
int				enqueue(struct s_queue *queue, char *content);
char			*dequeue(struct s_queue *queue);
char			*peekq(struct s_queue *queue);

struct s_stack	*inits();
int				*pop(struct s_stack *stack);
int				push(struct s_stack *stack, int *content);
int				*peeks(struct s_stack *stack);
void			prints(int c, struct s_stack *a, struct s_stack *b);

void			sa(struct s_stack *a, struct s_stack *b);
void			sb(struct s_stack *a, struct s_stack *b);
void			ss(struct s_stack *a, struct s_stack *b);
void			pa(struct s_stack *a, struct s_stack *b);
void			pb(struct s_stack *a, struct s_stack *b);
void			ra(struct s_stack *a, struct s_stack *b);
void			rb(struct s_stack *a, struct s_stack *b);
void			rr(struct s_stack *a, struct s_stack *b);
void			rra(struct s_stack *a, struct s_stack *b);
void			rrb(struct s_stack *a, struct s_stack *b);
void			rrr(struct s_stack *a, struct s_stack *b);

int				dispatch_checker(struct s_checker *c_s);
int				check_resault(struct s_checker *c_s);
void			check_arg_flag(struct s_checker *c_s, char **av, int *i);
void			print_color(int c, struct s_snode *a, struct s_snode *b);
#endif
