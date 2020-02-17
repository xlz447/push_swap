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

static char		*condense(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sb")) ||
		(!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sa")))
		return ("ss");
	else if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rb")) ||
			(!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "ra")))
		return ("rr");
	else if ((!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "rrb")) ||
			(!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rra")))
		return ("rrr");
	else
		return (NULL);
}

static void		optimize_print(struct s_pushswap *p_s)
{
	char	*tmp;
	char	*ins;

	while (p_s->ins->first)
	{
		tmp = dequeue(p_s->ins);
		if (tmp && peekq(p_s->ins))
		{
			ins = condense(tmp, peekq(p_s->ins));
			if (!ins)
				ft_printf("%s\n", tmp);
			else
			{
				ft_printf("%s\n", ins);
				dequeue(p_s->ins);
			}
			tmp = NULL;
		}
		if (tmp)
			ft_printf("%s\n", tmp);
	}
}

static void		clearp_exit(struct s_pushswap *p_s, int exit)
{
	if (p_s)
	{
		if (p_s->a)
			clear_stack(p_s->a);
		if (p_s->b)
			clear_stack(p_s->b);
		if (p_s->ins)
			clear_queue(p_s->ins);
		free(p_s);
	}
	if (exit)
		ft_errorexit("Error");
}

int				main(int ac, char **av)
{
	struct s_pushswap	*p_s;
	int					err;

	if (ac < 2 && (err = 1))
		exit(0);
	if (!(p_s = initpushswap(ac, av, &err)) || err == -1)
		clearp_exit(p_s, 1);
	sort_update(p_s->a);
	calc_group(p_s);
	radix_sort(p_s);
	optimize_print(p_s);
	return (0);
}
