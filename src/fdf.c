/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:21:05 by max               #+#    #+#             */
/*   Updated: 2022/12/01 16:36:58 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_img	new_image(char *map, char *title)
{
	t_img	img;

	img.map = map;
	img.proportion = TILE_HEIGHT >> 1;
	img.width = WINDOW_WIDTH;
	img.height = WINDOW_HEIGHT;
	window_minimum_size(&img);
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, img.width, img.height, title);
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	return img;
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

static void	start_hooks(t_img *img)
{
	close_window(img);
	change_depth(img);
}

int main(int argc, char **argv)
{
	t_img	img;
	char	*map;

	argv_validation(argc, argv);
	map = get_map(argv[1]);
	img = new_image(map, "Isometrics");
	draw_map(&img, map);
	start_hooks(&img);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0);
    mlx_loop(img.mlx);
    return (0);
}
