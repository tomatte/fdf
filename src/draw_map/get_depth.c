/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:11 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/08 20:52:48 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_depth(int depth, t_map *map, t_img *img)
{
	int	proportion;
	int	result;

	proportion = map->tile_height >> map->depth_shift;
	proportion = proportion >> img->depth_shift;
	if (!proportion)
		proportion = 1;
	result = depth * proportion;
	return (result);
}
