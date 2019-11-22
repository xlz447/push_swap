/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:00:16 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/19 20:00:17 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int				atoicheck(char *str, int *err)
{
	long long int	result;
	int				negative;

	result = 0;
	negative = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
		*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	if (*str == '\0')
		return (*err = -1);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if ((*str != '\0') || (negative == 1 && result > 2147483647) ||
		(negative == -1 && result > 2147483648))
		return (*err = -1);
	return (result * negative);
}

static struct s_checker	*initchecker(int ac, char **av, int *err)
{
	struct s_checker	*out;
	int					i;
	int					*n;

	if (NULL == (out = malloc(sizeof(struct s_checker))))
		return (NULL);
	out->a = inits();
	out->b = inits();
	out->ins = initq();
	out->vflag = 0;
	out->cflag = 0;
	i = ac - 1;
	while (i > 0)
	{
		if (NULL == (n = malloc(sizeof(int))) && (*err = -1))
			break ;
		check_arg_flag(out, av, &i);
		*n = atoicheck(av[i--], err);
		if (*err == -1)
			break ;
		if ((*err = push(out->a, n)) == -1)
			break ;
	}
	return (out);
}

static void				clearrss_exit(struct s_checker *c_s, int exit)
{
	if (c_s)
	{
		if (c_s->a)
		{
			while (c_s->a->top)
				pop(c_s->a);
			free(c_s->a);
		}
		if (c_s->b)
		{
			while (c_s->b->top)
				pop(c_s->b);
			free(c_s->b);
		}
		if (c_s->ins)
		{
			while (c_s->ins->first)
				dequeue(c_s->ins);
			free(c_s->ins);
		}
		free(c_s);
	}
	if (exit)
		ft_errorexit("Error");
}

static int				readins(struct s_checker *c_s)
{
	char	*line;
	int		rtn;

	while ((rtn = get_next_line(0, &line)) > 0)
	{
		if (enqueue(c_s->ins, line) < -1)
		{
			if (line)
				free(line);
			return (-1);
		}
	}
	return (rtn);
}

int						main(int ac, char **av)
{
	struct s_checker	*c_s;
	int					err;

	if (ac < 2 && (err = 1))
		exit(0);
	if (!(c_s = initchecker(ac, av, &err)) || err == -1 ||
		(readins(c_s) < 0) || (dispatch_checker(c_s) < 0))
		clearrss_exit(c_s, 1);
	check_resault(c_s);
	clearrss_exit(c_s, 0);
	return (0);
}
