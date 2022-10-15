#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line_x(int x, int y, int length, t_data img)
{
	while (length--)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
	}
}

void	draw_line_y(int x, int y, int length, t_data img)
{
	while (length--)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int	lx;
	int	ly;
	int	times;
	int	lines;
	int	l;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_line_x(10, 10, 50, img);
	draw_line_y(10, 10, 50, img);

	lx = 10;
	ly = 10;
	times = 11;
	lines = 20;
	while (times--)
	{
		l = lines;
		while (l--)
		{
			draw_line_x(lx, ly, 50, img);
			lx += 50;
		}
		ly += 50;
		lx = 10;
	}

	lx = 10;
	ly = 10;
	times = 21;
	lines = 10;
	while (times--)
	{
		l = lines;
		while (l--)
		{
			draw_line_y(lx, ly, 50, img);
			ly += 50;
		}
		lx += 50;
		ly = 10;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
