/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_columns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:16 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 18:01:48 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_map_columns(t_dot *dots)
{
	int	columns;

	columns = 0;
	while (dots)
	{
		columns++;
		dots = (t_dot *) dots->front;
	}
	return (columns);
}
