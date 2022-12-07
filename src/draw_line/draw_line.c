/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:14:52 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 17:29:40 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	walk_longest(t_line *line)
{
	line->proportion -= line->longest;
	line->x += line->dx1;
	line->y += line->dy1;
}

static void	walk_both(t_line *line)
{
	line->x += line->dx2;
	line->y += line->dy2;
}

static void	walk_pixel(t_line *line)
{
	if (line->proportion >= line->longest)
		walk_longest(line);
	else
		walk_both(line);
}

void	draw_line(t_img *img, t_line line)
{
	int	i;

	asign_values(&line);
	i = 0;
	while (i++ <= line.longest)
	{
		my_mlx_pixel_put(img, line.x, line.y, line.color);
		line.proportion += line.shortest;
		walk_pixel(&line);
	}
}
