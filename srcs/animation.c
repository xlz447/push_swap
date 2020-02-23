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

void		execute_one(struct s_checker *c_s)
{
	int		i;
	char	*tmp;

	init_const_array(c_s->op_func_array, c_s->ops_array);
	i = -1;
	while (++i < 11 && peekq(c_s->ins))
	{
		if (ft_strequ(c_s->ops_array[i], peekq(c_s->ins)))
		{
			c_s->op_func_array[i](c_s->a, c_s->b);
			break ;
		}
	}
	tmp = dequeue(c_s->ins);
	free(tmp);
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
			i % WIN_WIDTH < 20 + m->width_per_value * *tmp1->content) ||
			(i % WIN_WIDTH > WIN_WIDTH / 2 + 10 &&
			tmp2 && i % WIN_WIDTH < m->width_per_value * *tmp2->content +
			WIN_WIDTH / 2 + 10)))
				((int*)m->addr)[i] = 0xffdab9;
		tmp1 = (tmp1) ? tmp1->next : NULL;
		tmp2 = (tmp2) ? tmp2->next : NULL;
	}
}

static void	*timed_execute(void *args)
{
	struct s_mlx		*m;
	struct s_checker	*c_s;

	c_s = ((struct s_thread *)args)->c_s;
	m = ((struct s_thread *)args)->m;
	while (peekq(c_s->ins))
	{
		usleep(5000);
		execute_one(c_s);
		ft_bzero(m->addr, WIN_WIDTH * WIN_HEIGHT * m->b_p_p / 8);
		draw_stack(c_s, m);
		mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
		mlx_do_sync(m->mlx);
	}
	return (NULL);
}

static int	key_handler(int k, void *in[2])
{
	struct s_mlx		*m;
	struct s_checker	*c_s;

	c_s = (struct s_checker *)in[0];
	m = (struct s_mlx *)in[1];
	if (k == 53)
		exit(checker_result(c_s));
	else if (k == 49 && c_s->sflag)
	{
		execute_one(c_s);
		ft_bzero(m->addr, WIN_WIDTH * WIN_HEIGHT * m->b_p_p / 8);
		draw_stack(c_s, m);
		mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	}
	return (0);
}

void		animation(struct s_checker *c_s)
{
	struct s_mlx	m;
	struct s_thread args;
	pthread_t		thread;
	pthread_attr_t	attr;

	args.m = &m;
	args.c_s = c_s;
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIN_WIDTH, WIN_HEIGHT, "Checker");
	m.img = mlx_new_image(m.mlx, WIN_WIDTH, WIN_HEIGHT);
	m.max_width = (WIN_WIDTH - 60) / 2;
	m.width_per_value = m.max_width / (double)c_s->a->max;
	m.height_per_node = (WIN_HEIGHT - 40) / (double)c_s->a->size;
	m.addr = mlx_get_data_addr(m.img, &m.b_p_p, &m.size_line, &m.endian);
	draw_stack(c_s, &m);
	mlx_key_hook(m.win, key_handler, (void*[2]){c_s, &m});
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	if (c_s->aflag)
	{
		pthread_attr_init(&attr);
		pthread_create(&thread, &attr, &timed_execute, &args);
	}
	mlx_loop(m.mlx);
}
