/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:14:52 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 20:18:40 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	walk_longest(t_line *line_data)
{
	line_data->proportion -= line_data->longest;
	line_data->x += line_data->dx1;
	line_data->y += line_data->dy1;
}

static void	walk_both(t_line *line_data)
{
	line_data->x += line_data->dx2;
	line_data->y += line_data->dy2;
}

static void	walk_pixel(t_line *line_data)
{
	if (line_data->proportion >= line_data->longest)
		walk_longest(line_data);
	else
		walk_both(line_data);
}

void	draw_line(t_img *img, t_line line_data)
{
	int	i;

	asign_values(&line_data);
	i = 0;
	while (i++ <= line_data.longest)
	{
		verify_pixel(img, &line_data);
		my_mlx_pixel_put(img, line_data.x, line_data.y, line_data.color);
		line_data.proportion += line_data.shortest;
		walk_pixel(&line_data);
	}
}
