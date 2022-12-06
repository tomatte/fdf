/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:21 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 18:06:50 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_map_lines(t_dot *dots)
{
	int	lines;

	lines = 0;
	while (dots)
	{
		lines++;
		dots = (t_dot *) dots->down;
	}
	return (lines);
}
