/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:51:25 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 16:58:26 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_map	fill_map(t_dot	*dots)
{
	t_map	map;

	map.lines = get_map_lines(dots);
	map.columns = get_map_columns(dots);
	return (map);
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

void	draw_map(t_img *img)
{
	t_map	map;

	map = fill_map(img->dots);
	calculate_tile_size(img, &map);
	drawing(img, &map, img->dots);
}
