/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:21 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/26 14:15:22 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_map_lines(char *map)
{
	int	i;

	if (!map)
		error_exit("Map is NULL.\n");
	i = 1;
	while (1)
	{
		map = ft_strchr(map, '\n');
		if (!map || !*map)
			return (i);
		map++;
		i++;
	}
}
