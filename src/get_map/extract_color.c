#include "../fdf.h"

int	extract_color(char **map)
{
	int	color;

	if (**map == ',')
		(*map)++;
	else
		return (DEFAULT_COLOR);
	color = ft_hextoi_mod(map);
	return (color);
}
