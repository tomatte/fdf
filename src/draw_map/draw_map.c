/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:51:25 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/28 12:02:18 by dbrandao         ###   ########.fr       */
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


static t_position	new_position(int i, int j, int i2, int j2)
{
	t_position	position;

	position.i = i;
	position.j = j;
	position.i2 = i2;
	position.j2 = j2;
	return (position);
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
		{
			draw_isometric_line(img, map, pos_front(pos, current));
			pos.j++;
		}	
		if (current->down)
			draw_isometric_line(img, map, pos_down(pos, current));
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
	dots = get_map_values(map.map);
	drawing(img, &map, dots);
}
