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

int			check_resault(struct s_checker *c_s)
{
	if (c_s->b->size != 0)
		return (ft_printf("KO\n"));
	while (c_s->a->top->next)
	{
		if (*c_s->a->top->content < *c_s->a->top->next->content)
			c_s->a->top = c_s->a->top->next;
		else
			return (ft_printf("KO\n"));
	}
	return (ft_printf("OK\n"));
}

void		check_arg_flag(struct s_checker *c_s, char **av, int *i)
{
	int ref;

	while ((*i) > 0)
	{
		ref = *i;
		if (ft_strequ(av[*i], "-v"))
		{
			c_s->vflag = 1;
			(*i)--;
		}
		if (ft_strequ(av[*i], "-c"))
		{
			c_s->cflag = 1;
			(*i)--;
		}
		if (ref == *i)
			break ;
	}
}

void		print_color(int c, struct s_snode *an, struct s_snode *bn)
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

static void	init_const_array(struct s_checker *c_s)
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

int			dispatch_checker(struct s_checker *c_s)
{
	int		i;
	char	*tmp;

	init_const_array(c_s);
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
			prints(c_s);
	}
	return (0);
}
