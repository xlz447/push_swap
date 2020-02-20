# include "checker.h"
# define WIN_WIDTH 860
# define WIN_HEIGHT 640
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
	m.win = mlx_new_window(m.mlx, WIN_WIDTH, WIN_HEIGHT, "Checker");
	m.img = mlx_new_image(m.mlx, WIN_WIDTH, WIN_HEIGHT);
	m.max_width = WIN_WIDTH / 2 - 10;
	m.width_per_value = m.max_width / c_s->a->max;
	m.height_per_node = (WIN_HEIGHT - 40) / c_s->a->size;
	m.addr = mlx_get_data_addr(m.img, &m.bits_per_pixel, &m.size_line, &m.endian);
	ft_printf("bits_per_pixel=%d size_line=%d endian=%d\n", m.bits_per_pixel, m.size_line, m.endian);
	for (int i = 0; i < 50000; ++i)
		((int*)m.addr)[i] = 0xffdab9;
	mlx_key_hook(m.win, key_handler, &m);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	mlx_loop(m.mlx);
}
