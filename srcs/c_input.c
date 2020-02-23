/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:42:14 by xzhu              #+#    #+#             */
/*   Updated: 2019/12/05 21:42:15 by xzhu             ###   ########.fr       */
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

static void				check_flags(struct s_checker *c_s, char **av, int *i)
{
	int ref;

	while (42)
	{
		ref = *i;
		if ((*i) >= 0 && ft_strequ(av[*i], "-v") && --(*i) >= -1)
			c_s->vflag = 1;
		if ((*i) >= 0 && ft_strequ(av[*i], "-c") && --(*i) >= -1)
			c_s->cflag = 1;
		if ((*i) >= 0 && ft_strequ(av[*i], "-f") && --(*i) >= -1)
			c_s->fflag = 1;
		if ((*i) >= 0 && ft_strequ(av[*i], "-a") && --(*i) >= -1)
		{
			c_s->aflag = 1;
			c_s->sflag = 0;
		}
		if ((*i) >= 0 && ft_strequ(av[*i], "-s") && --(*i) >= -1)
			c_s->sflag = 1;
		if (ref == *i || (*i) < 0)
			break ;
	}
}

static char				**concat_input(int ac, char **av)
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

static struct s_checker	*init_c_mem(void)
{
	struct s_checker	*out;

	if (NULL == (out = ft_memalloc(sizeof(struct s_checker))))
		return (NULL);
	out->a = inits();
	out->b = inits();
	out->ins = initq();
	out->vflag = 0;
	out->cflag = 0;
	out->fflag = 0;
	out->aflag = 0;
	out->sflag = 0;
	return (out);
}

struct s_checker		*initchecker(int ac, char **av, int *err)
{
	struct s_checker	*out;
	int					i;
	int					*n;

	if (NULL == (out = init_c_mem()))
		return (NULL);
	av = concat_input(ac, av);
	i = 0;
	while (av[i] && av[i + 1])
		i++;
	while (i >= 0)
	{
		check_flags(out, av, &i);
		if (i < 0)
			break ;
		if (NULL == (n = malloc(sizeof(int))))
			return (NULL);
		*n = atoicheck(av[i--], err);
		if (-1 == *err)
			free(n);
		if (-1 == *err || -1 == push(out->a, n))
			break ;
	}
	ft_free_2d((void**)av);
	return (out);
}
