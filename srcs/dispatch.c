/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 22:19:06 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/20 22:19:08 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		expo(int b, int p)
{
	int		i;
	int		out;

	i = -1;
	out = 1;
	while (++i < p)
		out *= b;
	return (out);
}

void	init_const_array(t_op_function **op_func_array, char **ops_array)
{
	op_func_array[0] = &sa;
	op_func_array[1] = &sb;
	op_func_array[2] = &ss;
	op_func_array[3] = &pa;
	op_func_array[4] = &pb;
	op_func_array[5] = &ra;
	op_func_array[6] = &rb;
	op_func_array[7] = &rr;
	op_func_array[8] = &rra;
	op_func_array[9] = &rrb;
	op_func_array[10] = &rrr;
	ops_array[0] = "sa";
	ops_array[1] = "sb";
	ops_array[2] = "ss";
	ops_array[3] = "pa";
	ops_array[4] = "pb";
	ops_array[5] = "ra";
	ops_array[6] = "rb";
	ops_array[7] = "rr";
	ops_array[8] = "rra";
	ops_array[9] = "rrb";
	ops_array[10] = "rrr";
}

int		dispatch_checker(struct s_checker *c_s)
{
	int		i;
	char	*tmp;

	init_const_array(c_s->op_func_array, c_s->ops_array);
	while (peekq(c_s->ins))
	{
		i = -1;
		while (++i < 11)
		{
			if (ft_strequ(c_s->ops_array[i], peekq(c_s->ins)))
			{
				c_s->op_func_array[i](c_s->a, c_s->b);
				break ;
			}
		}
		if (i == 11)
			return (-1);
		tmp = dequeue(c_s->ins);
		free(tmp);
		if (c_s->vflag == 1)
			print_stack(c_s->cflag, c_s->a, c_s->b);
	}
	return (0);
}
