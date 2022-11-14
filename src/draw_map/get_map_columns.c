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
	while (**str && **str != ' ' &&  **str != '\t' && **str != '\n')
		(*str)++;
}

int	get_map_columns(char *map)
{
	int	columns;

	columns = 1;
	while (1)
	{
		move_chars(&map);
		move_spaces(&map);
		if (!ft_isalnum(*map))
			return (columns);
		columns++;
	}
}
