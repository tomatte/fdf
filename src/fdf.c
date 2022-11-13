#include "fdf.h"

static t_data	new_image(int width, int height, char *title)
{
	t_data	img;

	img.width = width;
	img.height = height;
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, width, height, title);
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	return img;
}

static void	render_image(t_data *img)
{
    mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
    mlx_loop(img->mlx);
	ft_printf("program ended.\n");
}

static void	argv_validation(int argc, char **argv)
{
	char	*type;
	if (argc < 2)
	{
		ft_printf("You need to pass a .fdf file as argument!\n");
		exit(EXIT_FAILURE);
	}
    argv[1]++;
	type = ft_strchr(argv[1], '.');
	if (!type || ft_strncmp(type, ".fdf", 4) || type[4])
    {
		ft_printf("Invalid file!\n");
		exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
	t_data	img;

	argv_validation(argc, argv);
	img = new_image(1080, 720, "Land");
	//draw_map(&img, argv[1]);
	render_image(&img);
    return (0);
}
