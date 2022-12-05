/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_columns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:16 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 00:20:29 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	move_spaces(char **str)
{
	if (!*str)
		return ;
	while (**str == ' ' || **str == '\t')
		(*str)++;
}

static void	move_chars(char **str)
{
	if (!*str)
		return ;
	while (**str && **str != ' ' && **str != '\t' && **str != '\n')
		(*str)++;
}

int	get_map_columns(char *map)
{
	int	columns;

	if (!map)
		error_exit("Map is NULL.\n");
	columns = 1;
	while (1)
	{
		move_chars(&map);
		move_spaces(&map);
		if (*map == '-')
			map++;
		if (!ft_isdigit(*map))
			return (columns);
		columns++;
	}
}
