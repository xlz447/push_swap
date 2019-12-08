/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:55:18 by xzhu              #+#    #+#             */
/*   Updated: 2019/12/05 21:55:19 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			atoicheck(char *str, int *err)
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

static char			**concat_input(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	char	**out;

	i = 0;
	j = 0;
	while (++i < ac)
		j += ft_strlen(av[i]);
	tmp = ft_strnew(j + ac - 2);
	i = 0;
	j = -1;
	k = 0;
	while (++i < ac)
	{
		if (k > 0)
			tmp[k++] = ' ';
		while (av[i][++j])
			tmp[k++] = av[i][j];
		j = -1;
	}
	out = ft_strsplit(tmp, ' ');
	free(tmp);
	return (out);
}

struct s_pushswap	*initpushswap(int ac, char **av, int *err)
{
	struct s_pushswap	*out;
	int					i;
	int					*n;

	if (NULL == (out = malloc(sizeof(struct s_pushswap))))
		return (NULL);
	out->a = inits();
	out->b = inits();
	out->ins = initq();
	av = concat_input(ac, av);
	i = 0;
	while (av[i + 1])
		i++;
	while (i >= 0)
	{
		if (NULL == (n = malloc(sizeof(int))))
			return (NULL);
		*n = atoicheck(av[i--], err);
		if (*err == -1)
			break ;
		if ((*err = push(out->a, n)) == -1)
			break ;
	}
	ft_free_2d((void**)av);
	return (out);
}
