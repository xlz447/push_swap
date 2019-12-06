/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 00:05:29 by xzhu              #+#    #+#             */
/*   Updated: 2019/12/06 00:05:34 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		print_color(int c, struct s_snode *an, struct s_snode *bn)
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

void			print_stack(int c, struct s_stack *a, struct s_stack *b)
{
	struct s_snode	*tmp1;
	struct s_snode	*tmp2;

	tmp1 = a->top;
	tmp2 = b->top;
	ft_printf("***********************\n");
	while (tmp1 || tmp2)
	{
		print_color(c, tmp1, tmp2);
		if (tmp1)
			tmp1->delta = 0;
		if (tmp2)
			tmp2->delta = 0;
		tmp1 = (tmp1) ? tmp1->next : tmp1;
		tmp2 = (tmp2) ? tmp2->next : tmp2;
	}
	ft_printf("----------- -----------\n     a           b     \n");
}
