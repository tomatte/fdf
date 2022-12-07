/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:14:57 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 17:30:02 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_line	line_coordinates(int x, int y, int x2, int y2)
{
	t_line	line;

	line.x = x;
	line.y = y;
	line.x2 = x2;
	line.y2 = y2;
	return (line);
}
