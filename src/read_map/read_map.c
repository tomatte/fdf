#include "../fdf.h"

static int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed to open the file \"%s\"\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/* static char	*read_file(int fd)
{
	int	map_size;

	map_size = get_file_size(fd);
	return (full_file())
} */

char    *read_map(char *file_name)
{
	char	*map;
	int		fd;

	fd = open_file(file_name);
	//map = read_file(fd);
	//validate_map(map);
	return (map);
}
