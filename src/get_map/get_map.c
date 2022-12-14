/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:26 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/05 23:24:57 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open the file\n");
	return (fd);
}

static void	remove_border_spaces(char **str)
{
	char	*aux;

	aux = *str;
	*str = ft_strtrim(*str, " \n\t");
	mem_clear((void *) &aux);
}

char	*get_map(char *file_name)
{
	char	*map;
	int		fd;

	fd = open_file(file_name);
	map = read_file(fd);
	remove_border_spaces(&map);
	return (map);
}
