#include "../fdf.h"

int	get_depth(int x, int y, t_map *map, int proportion)
{
	int	depth;

	if (!proportion)
		proportion = 1;
	depth = get_number(x, y, map->map) * proportion;

	return (depth);
}
