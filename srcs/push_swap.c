/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:25:18 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/21 19:25:23 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int					atoicheck(char *str, int *err)
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

static struct s_pushswap	*initpushswap(int ac, char **av, int *err)
{
	struct s_pushswap	*out;
	int					i;
	int					*n;

	if (NULL == (out = malloc(sizeof(struct s_pushswap))))
		return (NULL);
	out->a = inits();
	out->b = inits();
	out->ins = initq();
	i = ac - 1;
	while (i > 0)
	{
		if (NULL == (n = malloc(sizeof(int))))
			return (NULL);
		*n = atoicheck(av[i--], err);
		if (*err == -1)
			break ;
		if ((*err = push(out->a, n)) == -1)
			break ;
	}
	return (out);
}

static void					clearp_exit(struct s_pushswap *p_s, int exit)
{
	if (p_s)
	{
		if (p_s->a)
		{
			while (p_s->a->top)
				pop(p_s->a);
			free(p_s->a);
		}
		if (p_s->b)
		{
			while (p_s->b->top)
				pop(p_s->b);
			free(p_s->b);
		}
		if (p_s->ins)
		{
			while (p_s->ins->first)
				dequeue(p_s->ins);
			free(p_s->ins);
		}
		free(p_s);
	}
	if (exit)
		ft_errorexit("Error");
}

int							main(int ac, char **av)
{
	struct s_pushswap	*p_s;
	int					err;

	if (ac < 2 && (err = 1))
		exit(0);
	if (!(p_s = initpushswap(ac, av, &err)) || err == -1)
		clearp_exit(p_s, 1);
	prints(1, p_s->a, p_s->b);
	clearp_exit(p_s, 0);
	return (0);
}
