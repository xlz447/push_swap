/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:33:12 by xzhu              #+#    #+#             */
/*   Updated: 2020/02/20 20:33:14 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define WIN_WIDTH 860
#define WIN_HEIGHT 640

static int	key_handler(int k, struct s_mlx *m)
{
	if (k == 53)
		exit(0);
	(void)m;
	return (0);
}

void		draw_stack(struct s_checker *c_s, struct s_mlx *m)
{
	int				n;
	int				i;
	int				max;
	struct s_snode	*tmp1;
	struct s_snode	*tmp2;

	tmp1 = c_s->a->top;
	tmp2 = c_s->b->top;
	max = (c_s->a->size > c_s->b->size) ? c_s->a->size : c_s->b->size;
	n = -1;
	while (++n <= max)
	{
		i = -1;
		while (++i < WIN_HEIGHT * WIN_WIDTH)
			if (i / WIN_WIDTH >= m->height_per_node * n + 20 &&
			i / WIN_WIDTH < m->height_per_node * (n + 1) + 20 &&
			((i % WIN_WIDTH > 20 && tmp1 &&
			i % WIN_WIDTH < m->width_per_value * *tmp1->content) ||
			(i % WIN_WIDTH > WIN_WIDTH / 2 + 10 &&
			tmp2 && i % WIN_WIDTH < m->width_per_value * *tmp2->content +
			WIN_WIDTH / 2 + 10)))
				((int*)m->addr)[i] = 0xffdab9;
		tmp1 = (tmp1) ? tmp1->next : NULL;
		tmp2 = (tmp2) ? tmp2->next : NULL;
	}
}

void		animation(struct s_checker *c_s)
{
	struct s_mlx	m;

	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIN_WIDTH, WIN_HEIGHT, "Checker");
	m.img = mlx_new_image(m.mlx, WIN_WIDTH, WIN_HEIGHT);
	m.max_width = (WIN_WIDTH - 60) / 2;
	m.width_per_value = m.max_width / c_s->a->max;
	m.height_per_node = (WIN_HEIGHT - 40) / c_s->a->size;
	m.addr = mlx_get_data_addr(m.img, &m.b_p_p, &m.size_line, &m.endian);
	dispatch_checker(c_s);
	draw_stack(c_s, &m);
	mlx_key_hook(m.win, key_handler, &m);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	mlx_loop(m.mlx);
}
