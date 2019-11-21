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

void		init_const_array(struct s_checker *c_s)
{
	c_s->op_func_array[0] = &sa;
	c_s->op_func_array[1] = &sb;
	c_s->op_func_array[2] = &ss;
	c_s->op_func_array[3] = &pa;
	c_s->op_func_array[4] = &pb;
	c_s->op_func_array[5] = &ra;
	c_s->op_func_array[6] = &rb;
	c_s->op_func_array[7] = &rr;
	c_s->op_func_array[8] = &rra;
	c_s->op_func_array[9] = &rrb;
	c_s->op_func_array[10] = &rrr;
	c_s->ops_array[0] = "sa";
	c_s->ops_array[1] = "sb";
	c_s->ops_array[2] = "ss";
	c_s->ops_array[3] = "pa";
	c_s->ops_array[4] = "pb";
	c_s->ops_array[5] = "ra";
	c_s->ops_array[6] = "rb";
	c_s->ops_array[7] = "rr";
	c_s->ops_array[8] = "rra";
	c_s->ops_array[9] = "rrb";
	c_s->ops_array[10] = "rrr";
}

int			dispatch(struct s_checker *c_s)
{
	int		i;
	char	*tmp;

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
		prints(c_s->a, "stack a:");
		prints(c_s->b, "stack b:");
	}
	return (0);
}
