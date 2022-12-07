/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_minimum_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:58:09 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 22:17:02 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	window_minimum_size(t_img *img)
{
	int	columns;
	int	lines;
	int	tile_width;

	tile_width = 4;
	columns = get_map_columns(img->dots);
	lines = get_map_lines(img->dots);
	while ((tile_width * columns) > img->width - 400
		|| (tile_width * lines) > img->width - 400)
	{
		img->width += 21;
		img->height += 9;
	}
}
