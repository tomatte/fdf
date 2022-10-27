#include "fdf.h"

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

t_line	get_line_data(int x, int y, int x2, int y2)
{
	t_line	line_data;

	line_data.x = x;
	line_data.y = y;
	line_data.x2 = x2;
	line_data.y2 = y2;
	return (line_data);
}

int	is_text(char *file_name)
{
	char *file_type;

	file_type = ft_strnstr(file_name, ".txt", ft_strlen(file_name));
	if (!file_type)
		return (0);
	return (!file_type[4]);
}

int	verify_inputs(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	return (is_text(argv[1]));
}

int main(int argc, char **argv)
{
	t_data	img;

	if (!verify_inputs(argc, argv))
		return (-1);
	init_fill(&img, 1080, 720, "Land");
	new_img(img.mlx, &img);
	draw_table(&img, argv[1]);
	ft_printf("end\n");
    return (0);
}
