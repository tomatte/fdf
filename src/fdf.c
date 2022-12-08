/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:21:05 by max               #+#    #+#             */
/*   Updated: 2022/12/08 17:41:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	new_image(t_img *img, char *map, char *title)
{
	ft_memset(img, 0, sizeof(t_img));
	img->map = map;
	img->width = WINDOW_WIDTH;
	img->height = WINDOW_HEIGHT;
	img->dots = get_map_values(map);
	image_minimum_size(img);
	img->mlx = mlx_init();
	img->window = mlx_new_window(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, title);
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(
			img->img,
			&img->bpp,
			&img->line_length,
			&img->endian
			);
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
	else if (argc > 2)
	{
		ft_printf("Only one argument is allowed!\n");
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
	mlx_key_hook(img->window, key_hooks, img);
	close_window_x(img);
}

int	main(int argc, char **argv)
{
	t_img	img;
	char	*map;

	argv_validation(argc, argv);
	map = get_map(argv[1]);
	new_image(&img, map, "Isometrics");
	draw_map(&img);
	start_hooks(&img);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
