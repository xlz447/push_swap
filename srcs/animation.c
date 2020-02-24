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

static void	draw_stack(struct s_checker *c_s, struct s_mlx *m, int color)
{
	double			n;
	int				i;
	struct s_snode	*t1;
	struct s_snode	*t2;

	t1 = c_s->a->top;
	t2 = c_s->b->top;
	i = -1;
	while (++i < (H - 40) * W)
	{
		n = i / (W * m->height_p_node);
		if (i / W >= (int)(m->height_p_node * n) &&
		i / W < (int)(m->height_p_node * (n + 1)) &&
		((i % W > 20 && t1 && i % W < 20 + m->width_p_value * *t1->content) ||
		(i % W > W / 2 + 10 && t2 && i % W < m->width_p_value * *t2->content +
		W / 2 + 10)))
			((int*)m->addr)[i] = color;
		if (i && t1 && (i % (int)(W * m->height_p_node) == 0))
			t1 = t1->next;
		if (i && t2 && (i % (int)(W * m->height_p_node) == 0))
			t2 = t2->next;
	}
}

static void	execute_one(struct s_checker *c_s)
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
	if (i == 11)
		exit(ft_printf("Error\n"));
	tmp = dequeue(c_s->ins);
	free(tmp);
}

static void	*timed_execute(void *args)
{
	struct s_mlx		*m;
	struct s_checker	*c_s;

	c_s = ((struct s_thread *)args)->c_s;
	m = ((struct s_thread *)args)->m;
	while (peekq(c_s->ins))
	{
		pthread_mutex_lock(&m->lock);
		if (m->pause)
		{
			pthread_mutex_unlock(&m->lock);
			continue ;
		}
		pthread_mutex_unlock(&m->lock);
		usleep(100000);
		execute_one(c_s);
		ft_bzero(m->addr, W * (H - 40) * m->b_p_p / 8);
		draw_stack(c_s, m, 0xffdab9);
		if (!peekq(c_s->ins))
			checker_result(c_s) ? draw_stack(c_s, m, 0xee0000) :
			draw_stack(c_s, m, 0x90ee90);
		mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 20);
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
	{
		if (peekq(c_s->ins))
			exit(checker_result(c_s));
		exit(0);
	}
	else if (k == 1)
	{
		pthread_mutex_lock(&m->lock);
		m->pause = (m->pause == 0) ? 1 : 0;
		pthread_mutex_unlock(&m->lock);
	}
	else if (k == 49 && c_s->sflag)
	{
		execute_one(c_s);
		ft_bzero(m->addr, W * (H - 40) * m->b_p_p / 8);
		draw_stack(c_s, m, 0xffdab9);
		mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 20);
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
	m.win = mlx_new_window(m.mlx, W, H, "Checker");
	m.img = mlx_new_image(m.mlx, W, H - 40);
	m.max_width = (W - 60) / 2;
	m.width_p_value = m.max_width / (double)c_s->a->max;
	m.height_p_node = (H - 40) / (double)c_s->a->size;
	m.addr = mlx_get_data_addr(m.img, &m.b_p_p, &m.size_line, &m.endian);
	m.pause = 0;
	pthread_mutex_init(&m.lock, NULL);
	draw_stack(c_s, &m, 0xffdab9);
	mlx_key_hook(m.win, key_handler, (void*[2]){c_s, &m});
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 20);
	if (!peekq(c_s->ins))
		checker_result(c_s);
	if (c_s->aflag && !pthread_attr_init(&attr))
		pthread_create(&thread, &attr, &timed_execute, &args);
	mlx_loop(m.mlx);
	pthread_mutex_destroy(&m.lock);
}
