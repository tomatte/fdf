/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_minimum_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:58:09 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/01 00:22:50 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* 
esse codigo é apenas um teste, pois ele é ineficiente e repetitivo

Melhorias a serem feitas depois:
	a quantidade de linhas e colunas devem ser calculadas usando o struct t_dot
	a struct t_map deve ser preenchida no arquivo fdf.c e passada para os outros arquivos

	btw: a string contendo o o map.fdf deve ser lida apenas para criar a struct t_dot
	após isso todas as consultas devem ser feitas usando a struct t_dot
	desse modo é possível aumentar consideravelmente a velocidade dos calculos
 */
void	window_minimum_size(t_img *img)
{
	int	columns;
	int	lines;
	int	tile_width;

	tile_width = 4;
	columns = get_map_columns(img->map);
	lines = get_map_lines(img->map);
	while ((tile_width * columns) > img->width - 400
		|| (tile_width / 2) * lines > img->width - 400)
	{
		img->width += 21;
		img->height += 9;
	}
}
