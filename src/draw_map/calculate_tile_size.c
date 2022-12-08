/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_tile_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:14:57 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/08 10:09:02 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	get_highest_depth(t_dot *dots)
{
	int	highest_depth;
	t_dot	*aux;

	highest_depth = dots->depth;
	aux = dots;
	while (dots)
	{
		if (ft_abs(dots->depth) > ft_abs(highest_depth))
			highest_depth = dots->depth;
		dots = (t_dot *) dots->front;
		if (!dots)
		{
			dots = aux->down;
			aux = dots;
		}
	}
	return (highest_depth);
}

static void	get_depth_shift(t_img *img, t_map *map)
{
	int	highest_depth;

	highest_depth = get_highest_depth(img->dots);
	if (ft_abs(highest_depth) < 16)
		map->depth_shift = 1;
	else if (ft_abs(highest_depth) < 32)
		map->depth_shift = 2;
	else if (ft_abs(highest_depth) < 64)
		map->depth_shift = 3;
	else if (ft_abs(highest_depth) < 96)
		map->depth_shift = 4;
	else
		map->depth_shift = 5;
}

void	calculate_tile_size(t_img *img, t_map *map)
{
	int	width;

	width = 4;
	while (width + 2 < 96)
	{
		if (((width + 2) * map->columns) < img->width - 400
			&& ((width + 2) / 2) * map->lines < img->width - 400)
			width += 2;
		else
			break ;
	}
	map->tile_width = width;
	map->tile_height = width / 2;
	get_depth_shift(img, map);
}
