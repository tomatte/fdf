/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:21:05 by max               #+#    #+#             */
/*   Updated: 2022/11/23 21:54:31 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_img	new_image(int width, int height, char *title)
{
	t_img	img;

	img.proportion = TILE_HEIGHT >> 1;
	img.width = width;
	img.height = height;
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, width, height, title);
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	return img;
}

void	render_image(t_img *img)
{
    mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
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
	img = new_image(WINDOW_WIDTH, WINDOW_HEIGHT, "Isometrics");
	map = get_map(argv[1]);
	img.map = map;
	draw_map(&img, map);
	start_hooks(&img);
	render_image(&img);
    mlx_loop(img.mlx);
    return (0);
}

/* 
TO-DO:
 -por map dentro de MAP
 -calcular tamanho do map automaticamente 
 */