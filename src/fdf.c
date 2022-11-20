#include "fdf.h"

static t_img	new_image(int width, int height, char *title)
{
	t_img	img;

	img.width = width;
	img.height = height;
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, width, height, title);
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	return img;
}

static void	render_image(t_img *img)
{
    mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	ft_printf("rendering map...");
    mlx_loop(img->mlx);
	ft_printf("program ended.\n");
}

static void	argv_validation(int argc, char **argv)
{
	char	*type;
	char	*file_name;

	if (argc < 2)
	{
		ft_printf("You need to pass a .fdf file as argument!\n");
		exit(EXIT_FAILURE);
	}
	file_name = argv[1];
    file_name++;
	type = ft_strchr(file_name, '.');
	if (!type || ft_strncmp(type, ".fdf", 4) || type[4])
    {
		ft_printf("Invalid file!\n");
		exit(EXIT_FAILURE);
    }
}

void	start_hooks(t_img *img)
{
	close_window(img);
}

int main(int argc, char **argv)
{
	t_img	img;
	char	*map;

	argv_validation(argc, argv);
	img = new_image(1080, 720, "Land");
	map = get_map(argv[1]);
	draw_map(&img, map);
	start_hooks(&img);
	render_image(&img);
    return (0);
}
