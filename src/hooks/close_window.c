#include "../fdf.h"

static int	close_w(int key_code, t_img *img)
{
	if (key_code == ESC)
		mlx_destroy_window(img->mlx, img->window);
	return (0);
}

void	close_window(t_img *img)
{
	mlx_key_hook(img->window, close_w, img);
}
