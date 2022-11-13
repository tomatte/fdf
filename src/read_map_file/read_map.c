#include "../fdf.h"

int	open_file(char *file_name)
{

}

char	*read_file(int fd)
{
	int	map_size;

	map_size = get_file_size(fd);
	return (full_file())
}

char    *read_map(char *file_name)
{
	char	*map;
	int		fd;

	fd = open_file(file_name);
	map = read_file(fd);
	validate_map(map);
	return (map);
}