/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:05:07 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 00:05:08 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	extract_color(char **map)
{
	int	color;

	if (**map == ',')
		(*map)++;
	else
		return (DEFAULT_COLOR);
	color = ft_hextoi_mod(map);
	return (color);
}
