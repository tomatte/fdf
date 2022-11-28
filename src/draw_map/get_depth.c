/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:11 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/28 12:15:08 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_depth(int depth, t_map *map, t_img *img)
{
	int	proportion;
	int	result;

	proportion = map->tile_height >> 1;
	if (!proportion)
		proportion = 1;
	while (proportion * depth > img->height / 2 - 200)
		depth -= 1;
	while (depth * proportion < -1 * (img->height / 2 - 200))
		depth += 1;
	return (depth * proportion);
}
