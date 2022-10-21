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
	else if (file_type[4])
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_data	img;

	if (argc < 2)
		return (-1);
	else if (!is_text(argv[1]))
		return (-1);
	
	init_fill(&img, 1080, 720, "Land");
	new_img(img.mlx, &img);
    return (0);
}
