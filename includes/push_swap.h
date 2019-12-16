/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:42:05 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/21 19:42:06 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"

struct				s_pushswap {
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_queue	*ins;
	int				gsize;
};

struct s_pushswap	*initpushswap(int ac, char **av, int *err);
void				sort_update(struct s_stack *stack);
void				calc_group(struct s_pushswap *ps);
int					log_ceil(int n, int m);

#endif
