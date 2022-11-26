/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:11 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/26 14:15:12 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_depth(int x, int y, t_map *map, t_img *img)
{
	int	depth;
	int	proportion;
	int	result;

	proportion = map->tile_height >> 1;
	if (!proportion)
		proportion = 1;
	depth = get_number(x, y, map->map);
	while (proportion * depth > img->height / 2 - 200)
		depth -= 1;
	while (depth * proportion < -1 * (img->height / 2 - 200))
		depth += 1;
	ft_printf("proportion: %d\n", proportion);
	ft_printf("depth: %d\n", depth);
	ft_printf("result: %d\n", depth * proportion);
	return (depth * proportion);
}
