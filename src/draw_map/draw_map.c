/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:51:25 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/25 15:20:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_map	get_map_values(char *map_str)
{
	t_map	map;

	map.map = map_str;
	map.lines = get_map_lines(map.map);
	map.columns = get_map_columns(map.map);
	return (map);
}


static t_position	new_position(int i, int j, int i2, int j2)
{
	t_position	position;

	position.i = i;
	position.j = j;
	position.i2 = i2;
	position.j2 = j2;
	return (position);
}

static void	draw_y(t_img *img, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->lines - 1)
	{
		j = -1;
		while (++j < map->columns)
		{
			draw_isometric_line(img, map, new_position(i, j, i + 1, j));
		}
	}
}

static void	draw_x(t_img *img, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->lines)
	{
		
		j = -1;
		while (++j < map->columns - 1)
		{
			draw_isometric_line(img, map, new_position(i, j, i, j + 1));
		}
	}
}

void	calculate_tile_size(t_img *img, t_map *map)
{
	int	width;

	width = 2;
	while (1)
	{
		if (((width + 2) * map->columns) < img->width - 400
			&& ((width + 2) / 2) * map->lines < img->width - 400)
			width += 2;
		else
			break ;
	}
	map->tile_width = width;
	map->tile_height = width / 2;
}


void	draw_map(t_img *img, char *map_str)
{
	t_map	map;
	t_line	line;

	map = get_map_values(map_str);
	calculate_tile_size(img, &map);
	ft_printf("tile_width: %d\n", map.tile_width);
	ft_printf("tile_height: %d\n", map.tile_height);
	ft_printf("columns: %d\n", map.columns);
	ft_printf("lines: %d\n", map.lines);
	draw_x(img, &map);
	draw_y(img, &map);
}
