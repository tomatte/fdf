/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isometric_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:51:50 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 17:02:05 by dbrandao         ###   ########.fr       */
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

void	draw_isometric_line(t_img *img, t_map *map, t_position position)
{
	t_line	line;

	line.color = position.color;
	if (line.color == DEFAULT_COLOR)
		line.color = position.color2;
	line.x = get_pixel_x(img, position.i, position.j, map);
	line.y = get_pixel_y(img, position.i, position.j, map);
	line.x2 = get_pixel_x(img, position.i2, position.j2, map);
	line.y2 = get_pixel_y(img, position.i2, position.j2, map);
	line.y -= get_depth(position.depth, map);
	line.y2 -= get_depth(position.depth2, map);
	draw_line(img, line);
}
