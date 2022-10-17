#include "fdf.h"
#include "./libft/libftprintf.h"

void	new_img(void *mlx, t_data *img)
{
	img->img = mlx_new_image(mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
}

void	init_fill(t_data *img, int width, int height, char title[])
{
	img->width = width;
	img->height = height;
	img->mlx = mlx_init();
	img->window = mlx_new_window(img->mlx, width, height, title);
}

int main(void)
{
	t_data	img;

	ft_printf("Lib working!\n");
	init_fill(&img, 1080, 720, "Land");
	new_img(img.mlx, &img);
	line(&img, 0, 0, 400, 200);
	line(&img, 0, 300, 1080, 500);
	line(&img, 700, 700, 1000, 720);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0);
	mlx_loop(img.mlx);
    return (0);
}
