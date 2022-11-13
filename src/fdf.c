#include "fdf.h"

void	new_img(void *mlx, t_data *img)
{
	img->img = mlx_new_image(mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
}

static void	fill_img_data(t_data *img, int width, int height, char title[])
{
	img->width = width;
	img->height = height;
	img->mlx = mlx_init();
	img->window = mlx_new_window(img->mlx, width, height, title);
}

int	verify_file_type(char *file_name, char *file_type)
{

}

//provavelmente se o usuario mandar aquivo.algo.fdf irá passar na validação
//e isso deve ser considerado um erro
int	input_validation(int argc, char **argv)
{
	char	*type;

	if (argc < 2)
		exit(EXIT_FAILURE);
	type = ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]));
	if (!type || type[4])
		exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	t_data	img;

	input_validation(argc, argv);
	fill_img_data(&img, 1080, 720, "Land");
	new_img(img.mlx, &img);
	draw_map(&img, argv[1]);
	ft_printf("end\n");
    return (0);
}
