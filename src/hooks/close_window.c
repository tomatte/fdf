#include "../fdf.h"

static int	close_esc(int key_code, t_img *img)
{
	if (key_code == ESC)
		mlx_destroy_window(img->mlx, img->window);
	ft_printf("\nWindow closed\n");
	return (0);
}

static int	close_x(t_img *img)
{
	mlx_destroy_window(img->mlx, img->window);
	ft_printf("\nProgram closed\n");
	exit(0);
	return (0);
}

void	close_window(t_img *img)
{
	mlx_key_hook(img->window, close_esc, img);
	mlx_hook(img->window, 17, 1L<<17,  close_x, img);
}
