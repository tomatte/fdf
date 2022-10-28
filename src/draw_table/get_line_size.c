#include "../fdf.h"

static void	pass_spaces(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static void	pass_digits(char **str)
{
	while (ft_isdigit(**str))
		(*str)++;
}

int get_line_size(char *map_line)
{
	int i;

	i = 0;
	while (*map_line)
	{
		pass_spaces(&map_line);
		if (ft_isdigit(*map_line) || ft_issign(*map_line))
			i++;
		pass_digits(&map_line);
	}
	return (i);
}
