/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isometric_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:51:50 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/28 12:06:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	get_pixel_x(t_img *img, int i, int j, t_map *map)
{
	int		pixel_x;

	pixel_x = (j - i) * (map->tile_width / 2);
	pixel_x += img->width / 2;
	return (pixel_x);
}

static int	get_pixel_y(t_img *img, int i, int j, t_map *map)
{
	int		pixel_y;
	int		centralize_map;
	int		map_height;

	pixel_y = (i + j) * (map->tile_height / 2);
	map_height = (map->columns + map->lines) * (map->tile_height / 2);
	centralize_map = (img->height / 2) - (map_height / 2);
	pixel_y += centralize_map;
	return (pixel_y);
}

/* void	put_isometric_pixel(t_img *img, int x, int y, t_map *map)
{
	int	pixel_y;
	int	pixel_x;

	pixel_x = get_pixel_x(img, x, y);
	pixel_y = get_pixel_y(img, x, y, map);
	my_mlx_pixel_put(img, x, y, RED);
} */

void	draw_isometric_line(t_img *img, t_map *map, t_position position)
{
	t_line	line;

/* ft_printf("i: %d\n", position.i2);
ft_printf("j: %d\n", position.j2); */
/* ft_printf("position color: %d\n", position.color);
ft_printf("position depth: %d\n", position.depth);
ft_printf("position color2: %d\n", position.color2);
ft_printf("position depth2: %d\n", position.depth2);
 */
/* 	line.color = get_color(position.i, position.j, map->map);
	if (line.color == DEFAULT_COLOR)
		line.color = get_color(position.i2, position.j2, map->map);
	line.x = get_pixel_x(img, position.i, position.j, map);
	line.y = get_pixel_y(img, position.i, position.j, map);
	line.x2 = get_pixel_x(img, position.i2, position.j2, map);
	line.y2 = get_pixel_y(img, position.i2, position.j2, map);
	line.y -= get_depth(position.i, position.j, map, img);
	line.y2 -= get_depth(position.i2, position.j2, map, img); */
	draw_line(img, line);
}
