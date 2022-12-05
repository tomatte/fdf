/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:51:06 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/02 08:59:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	is_new_line(char **map)
{
	while (ft_isspace(**map))
	{
		if (**map == '\n')
			return (1);
		else
			(*map)++;
	}
	return (0);
}

static int	extract_color(char **map)
{
	int	color;

	if (**map == ',')
		(*map)++;
	else
		return (DEFAULT_COLOR);
	color = ft_hextoi_mod(map);
	return (color);
}

static void	*new_dot(char **map)
{
	t_dot	*dot;

	if (!map || !*map || !**map)
		return (NULL);
	dot = (t_dot *) malloc(sizeof(t_dot));
	if (!dot)
		return (NULL);
	dot->depth = ft_atoi_mod(map);
	dot->color = extract_color(map);
	dot->front = NULL;
	dot->down = NULL;
	return (dot);
}

void	get_first(t_dot **dots, t_dot **first, t_dot **current, t_dot **up, char **map)
{
	if (!*dots)
	{
		*dots = new_dot(map);
		*first = *dots;
		*current = *first;
	}
	else if (is_new_line(map))
	{
		*up = *first;
		*current = new_dot(map);
		*first = *current;
		(*up)->down = *current;
	}
}

void	get_next(t_dot **current, t_dot **up, char **map)
{
	(*current)->front = new_dot(map);
	*current = (*current)->front;
	if (*up && (*up)->front && *current)
	{
		(*up) = (*up)->front;
		(*up)->down = *current;
	}
}
