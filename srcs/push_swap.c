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
	// print_stack(1, p_s->a, p_s->b);
	sort_update(p_s->a);
	calc_group(p_s);
	radix_sort(p_s);
	// clearp_exit(p_s, 0);
	// print_stack(1, p_s->a, p_s->b);

	return (0);
}
