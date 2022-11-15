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
