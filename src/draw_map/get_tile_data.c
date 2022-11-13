#include "fdf.h"

static char	*read_map_line(int fd)
{

}

static int	get_coordinates_size(char *map_line)
{

}

static int	*get_values(char *map_line, int size)
{

}

t_tile	get_tile_data(int fd)
{
	t_tile	tile;
	char	*map_line;

	map_line = read_map_line(fd);
	tile.size = get_coordinates_size(map_line);
	tile.coordinates  = get_values(map_line, tile.size);
	return (tile);
}
