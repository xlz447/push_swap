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
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# define W 860
# define H 640
# define RED 0xff4d4d
# define GREEN 0x90ee90

struct				s_qnode {
	char			*content;
	struct s_qnode	*next;
};

struct				s_queue {
	struct s_qnode	*first;
	struct s_qnode	*last;
	unsigned		size;
};

struct				s_snode {
	int				*content;
	int				delta;
	int				index;
	int				group;
	struct s_snode	*next;
};

struct				s_stack {
	struct s_snode	*top;
	unsigned		size;
	int				max;
};

typedef	void		t_op_function(struct s_stack *a, struct s_stack *b);

struct				s_mlx {
	void			*mlx;
	void			*win;
	void			*img;
	int				max_width;
	double			width_p_value;
	double			height_p_node;
	int				b_p_p;
	int				size_line;
	int				endian;
	char			*addr;
	pthread_mutex_t lock;
	int				pause;
};

struct				s_checker {
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_queue	*ins;
	int				vflag;
	int				cflag;
	int				fflag;
	int				aflag;
	int				sflag;
	t_op_function	*op_func_array[11];
	char			*ops_array[11];
};

struct				s_thread {
	struct s_mlx		*m;
	struct s_checker	*c_s;
};

struct s_queue		*initq();
int					enqueue(struct s_queue *queue, char *content);
char				*dequeue(struct s_queue *queue);
char				*peekq(struct s_queue *queue);
void				clear_queue(struct s_queue *queue);

struct s_stack		*inits();
int					*pop(struct s_stack *stack);
int					push(struct s_stack *stack, int *content);
int					*peeks(struct s_stack *stack);
void				clear_stack(struct s_stack *stack);

void				sa(struct s_stack *a, struct s_stack *b);
void				sb(struct s_stack *a, struct s_stack *b);
void				ss(struct s_stack *a, struct s_stack *b);
void				pa(struct s_stack *a, struct s_stack *b);
void				pb(struct s_stack *a, struct s_stack *b);
void				ra(struct s_stack *a, struct s_stack *b);
void				rb(struct s_stack *a, struct s_stack *b);
void				rr(struct s_stack *a, struct s_stack *b);
void				rra(struct s_stack *a, struct s_stack *b);
void				rrb(struct s_stack *a, struct s_stack *b);
void				rrr(struct s_stack *a, struct s_stack *b);

struct s_checker	*initchecker(int ac, char **av, int *err);
int					checker_result(struct s_checker *c_s);
void				init_const_array(t_op_function	**op_func_array,
										char **ops_array);
int					dispatch_checker(struct s_checker *c_s);
void				print_stack(int c, struct s_stack *a, struct s_stack *b);
void				animation(struct s_checker *c_s);
#endif
