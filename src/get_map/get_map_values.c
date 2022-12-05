/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:04:58 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/05 23:25:54 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_dot	*get_map_values(char *map)
{
	t_dot	*dots;
	t_dot	*up;
	t_dot	*current;
	t_dot	*first;

	if (!map)
		return (NULL);
	up = NULL;
	first = NULL;
	current = NULL;
	dots = NULL;
	while (*map)
	{
		get_first(&dots, &first, &current, &up, &map);
		get_next(&current, &up, &map);
		if (!current)
			break ;
	}
	return (dots);
}

/* 
int	main(int argc, char **argv)
{
	t_dot	*dot;
	t_dot	*line;
	char	*map;

	map = get_map(argv[1]);
	dot = get_map_values(map);
	line = dot;

	while (dot)
	{
		ft_printf("%d:%d\t", dot->depth, dot->color);
		dot = (t_dot *) dot->front;
		if (!dot)
		{
			ft_printf("\n\n\n");
			dot = (t_dot *) line->down;
			line = dot;
		}
	}
	return (0);
}
 */
/*gcc map_struct.c read_file.c ../others/error_exit.c
../others/mem_clear.c ./get_map.c ../../libft/libftprintf.a
*/
/* 
	var a;
	var up;

	up = NULL;
	up = a;
	up->down = b
	up = up->front
	up->down = b2
	up = up->front
	up->down = b3;
	a - a2 - a3
	|	|  - |
	b - b2 - b3
	|
	c - c2 - c3

	up = up->down;
	up->down = c;

	c->front = c2;

	up = up->next
	up->down = c2;




 */