/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:11 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 16:59:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_depth(int depth, t_map *map)
{
	int	proportion;

	proportion = map->tile_height >> map->depth_shift;
	if (!proportion)
		proportion = 1;
	return (depth * proportion);
}
