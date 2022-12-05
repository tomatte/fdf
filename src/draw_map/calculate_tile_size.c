/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_tile_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:14:57 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 00:15:11 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	ft_printf("IMAGE WIDTH: %d\n", img->width);
	ft_printf("IMAGE HEIGHT: %d\n", img->height);
	map->tile_width = width;
	map->tile_height = width / 2;
}