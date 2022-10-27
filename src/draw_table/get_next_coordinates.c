#include "../fdf.h"

int find_number(char **str)
{
    int num;

    while (**str == ' ' || **str == '\t')
        (*str)++;
    if (ft_isdigit(**str))
    {
        num = ft_atoi(*str);
        while (ft_isdigit(**str))
            (*str)++;
        return (num);
    }
    return (-1);
}

int get_line_size(char *map_line)
{
    int i;

    if (!map_line)
        return (0);
    i = 0;
    while (find_number(&map_line) >= 0)
        i++;
    return (i);
}

int	*get_coordinates_array(int line_size)
{
	int	*coordinates;
	int	i;

	if (line_size <= 0)
		return (NULL);
	coordinates = ft_calloc(line_size + 1, sizeof(int));
	if (!coordinates)
		return (NULL);
	coordinates[0] = line_size + 1;
	return (coordinates);
}

void	fill_coordinates_array(int **coordinates, char *map_line)
{
	int	i;

	if (!*coordinates || !map_line)
		return ;
	i = 0;
	while (++i < **coordinates)
		(*coordinates)[i] = find_number(&map_line);
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
