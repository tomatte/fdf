/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:11 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/08 17:25:47 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_depth(int depth, t_map *map, t_img *img)
{
	int	proportion;
	int	result;

	proportion = map->tile_height >> map->depth_shift;
	if (!proportion)
		proportion = 1;
	result = depth * proportion;
	if (depth)
		result += img->depth_mod;
	return (result);
}
