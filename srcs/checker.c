/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:00:16 by xzhu              #+#    #+#             */
/*   Updated: 2019/11/19 20:00:17 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		clearc_exit(struct s_checker *c_s, int exit)
{
	if (c_s)
	{
		if (c_s->a)
			clear_stack(c_s->a);
		if (c_s->b)
			clear_stack(c_s->b);
		if (c_s->ins)
			clear_queue(c_s->ins);
		free(c_s);
	}
	if (exit)
		ft_errorexit("Error");
}

int				checker_result(struct s_checker *c_s)
{
	struct s_snode *tmp;

	if (c_s->b->size != 0)
		return (ft_printf("KO\n"));
	tmp = c_s->a->top;
	while (tmp && tmp->next)
	{
		if (*tmp->content < *tmp->next->content)
			tmp = tmp->next;
		else
			return (ft_printf("KO\n"));
	}
	return (ft_printf("OK\n") - 3);
}

static int		open_file(void)
{
	char	*filename;
	int		rtn;

	ft_printf("Enter a filename, followed by the Enter Key.\n");
	filename = NULL;
	rtn = get_next_line(0, &filename);
	if (rtn >= 0)
		rtn = open(filename, O_RDONLY);
	if (filename)
		free(filename);
	return (rtn);
}

static int		read_ins(struct s_checker *c_s)
{
	char	*line;
	int		rtn;
	int		fd;

	fd = (c_s->fflag) ? open_file() : 0;
	while ((rtn = get_next_line(fd, &line)) > 0)
	{
		if (enqueue(c_s->ins, line) < -1)
		{
			if (line)
				free(line);
			return (-1);
		}
	}
	return (rtn);
}

int				main(int ac, char **av)
{
	struct s_checker	*c_s;
	int					err;

	if (ac < 2 && (err = 1))
		exit(0);
	if (!(c_s = initchecker(ac, av, &err)) || err == -1 ||
		!c_s->a->size || (read_ins(c_s) < 0))
		clearc_exit(c_s, 1);
	if (c_s->aflag || c_s->sflag)
		animation(c_s);
	else
		err = dispatch_checker(c_s);
	if (!err)
		checker_result(c_s);
	clearc_exit(c_s, err);
	return (0);
}
