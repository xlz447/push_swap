# include "checker.h"

static int	key_handler(int k, struct s_mlx *m)
{
	if (k == 53)
		exit(0);
	(void)m;
	return (0);
}

void animation(struct s_checker *c_s)
{
	struct s_mlx	m;

	(void)c_s;
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, 600, 600, "Checker");
	m.img = mlx_new_image(m.mlx, 600, 600);
	mlx_key_hook(m.win, key_handler, &m);
	mlx_loop(m.mlx);
}
