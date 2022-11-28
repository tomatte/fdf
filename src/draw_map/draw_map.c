/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:51:25 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/28 17:53:08 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_map	fill_map(char *map_str)
{
	t_map	map;

	map.map = map_str;
	map.lines = get_map_lines(map.map);
	map.columns = get_map_columns(map.map);
	return (map);
}

void	calculate_tile_size(t_img *img, t_map *map)
{
	int	width;

	width = 4;
	while (1)
	{
		if (((width + 2) * map->columns) < img->width - 400
			&& ((width + 2) / 2) * map->lines < img->width - 400)
			width += 2;
		else
			break ;
	}
	if (width == 4)
	{
		while ((width * map->columns) > img->width - 400
			|| (width / 2) * map->lines > img->width - 400)
		{
			img->width += 21;
			img->height += 9;
		}
	}
	ft_printf("IMAGE WIDTH: %d\n", img->width);
	ft_printf("IMAGE HEIGHT: %d\n", img->height);
	map->tile_width = width;
	map->tile_height = width / 2;
}

t_position	pos_front(t_position pos, t_dot *dot) 
{
	pos.i2 = pos.i;
	pos.j2 = pos.j + 1;
	pos.depth = dot->depth;
	pos.depth2 = ((t_dot *) dot->front)->depth;
	pos.color = dot->color;
	pos.color2 = ((t_dot *) dot->front)->color;
	return (pos);
}

t_position	pos_down(t_position pos, t_dot *dot) 
{
	pos.i2 = pos.i + 1;
	pos.j2 = pos.j;
	pos.depth = dot->depth;
	pos.depth2 = ((t_dot *) dot->down)->depth;
	pos.color = dot->color;
	pos.color2 = ((t_dot *) dot->down)->color;
	return (pos);
}


void	drawing(t_img *img, t_map *map, t_dot *dots)
{
	t_dot		*current;
	t_dot		*line;
	t_position	pos;

	current = dots;
	line = current;
	pos.i = 0;
	pos.j = 0;
	while (current)
	{
		if (current->front)
			draw_isometric_line(img, map, pos_front(pos, current));
		if (current->down)
			draw_isometric_line(img, map, pos_down(pos, current));
		pos.j++;
		current = (t_dot *) current->front;
		if (!current)
		{
			current = (t_dot *) line->down;
			line = current;
			pos.j = 0;
			pos.i++;
		}
	}
}

void	draw_map(t_img *img, char *map_str)
{
	t_map	map;
	t_line	line;
	t_dot	*dots;

	map = fill_map(map_str);
	ft_printf("columns: %d\n", map.columns);
	ft_printf("lines: %d\n", map.lines);
	calculate_tile_size(img, &map);
	ft_printf("width: %d\n", map.tile_width);
	ft_printf("height: %d\n", map.tile_height);
	dots = get_map_values(map.map);
	drawing(img, &map, dots);
}
