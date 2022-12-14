/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:14:45 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 20:38:58 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	initialize_line_struct(t_line *line)
{
	int	test;

	line->w = line->x2 - line->x;
	line->h = line->y2 - line->y;
	line->longest = ft_abs(line->w);
	test = line->y2 - line->y;
	line->shortest = ft_abs(test);
}

static void	decide_xy_direction(t_line *line)
{
	if (line->w < 0)
	{
		line->dx1 = -1;
		line->dx2 = -1;
	}
	else if (line->w > 0)
	{
		line->dx1 = 1;
		line->dx2 = 1;
	}
	if (line->h < 0)
		line->dy1 = -1;
	else if (line->h > 0)
		line->dy1 = 1;
	if (line->longest <= line->shortest)
	{
		line->longest = ft_abs(line->h);
		line->shortest = ft_abs(line->w);
		if (line->h < 0)
			line->dy2 = -1;
		else if (line->h > 0)
			line->dy2 = 1;
		line->dx2 = 0;
	}
}

void	asign_values(t_line *line)
{
	initialize_line_struct(line);
	decide_xy_direction(line);
}
