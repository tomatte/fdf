#include "../fdf.h"

int	get_depth(int x, int y, t_map *map)
{
	int	depth;
	int	proportion;

	proportion = (TILE_HEIGHT >> 1);
	if (!proportion)
		proportion = 1;
	depth = get_number(x, y, map->map) * proportion;

	return (depth);
}
