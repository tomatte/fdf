#include "fdf.h"

static char	*read_map_line()
{
	
}

t_tile	get_tile_data(int fd)
{
	t_tile	tile;
	char	*map_line;

	map_line = read_map_line(fd);
	extract_values(&tile, map_line);
	return (tile);
}
