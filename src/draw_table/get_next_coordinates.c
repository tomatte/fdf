#include "../fdf.h"

static char	next_number(char **str)
{
	int	num;

	*str = ft_isnumber(*str);
	if (!*str || !**str)
		return (0);
	num = ft_atoi(*str);
	while (!ft_isspace(**str) || !**str)
		(*str)++;
	return (num);
}

static int	*get_coordinates_array(int line_size)
{
	int	*coordinates;

	if (line_size <= 0)
		return (NULL);
	coordinates = ft_calloc(line_size + 1, sizeof(int));
	if (!coordinates)
		return (NULL);
	coordinates[0] = line_size + 1;
	return (coordinates);
}

static void	fill_coordinates_array(int **coordinates, char *map_line)
{
	int	i;

	if (!*coordinates || !map_line)
		return ;
	i = 0;
	while (++i < **coordinates)
		(*coordinates)[i] = next_number(&map_line);
}

int *get_next_coordinates(int fd)
{
	char	*map_line;
	int		line_size;
	int		*coordinates;

	map_line = get_next_line(fd);
	line_size = get_line_size(map_line);
	coordinates = get_coordinates_array(line_size);
	fill_coordinates_array(&coordinates, map_line);
	return (coordinates);
}
