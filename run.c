#include "fdf.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	new_img(void *mlx, void *window, t_data *img)
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

void	draw_line(t_data *img, int x1, int y1, int x2, int y2)
{
	int	width;
	int	height;
	int	lower;
	int	r;
	int	times;
	
	width = x2 - x1;
	height = y2 - y1;
	if (x2 > y2)
	{
		r = x2 / y2;
		lower = y2;
	}
	else
	{
		r = y2 / x2;
		lower = x2;
	}
	times = r;
	while (lower >= 0)
	{
		while (times > 0)
		{
			if (x1 <= x2)
				my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
			x1++;
			times--;
		}
		y1++;
		if (lower > 0 && y1 <= y2)
			my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
		lower--;
		times = r;
	}
}

int main(void)
{
	t_data	img;

	init_fill(&img, 1080, 720, "Land");
	new_img(img.mlx, img.window, &img);
	draw_line(&img, 0, 0, 700, 50);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0);
	mlx_loop(img.mlx);
    return (0);
}

/* 
	 0, 0
	50, 100
 */