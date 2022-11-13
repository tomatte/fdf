#include "../fdf.h"

static int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open the file\n");
	return (fd);
}

char    *get_map(char *file_name)
{
	char	*map;
	int		fd;

	fd = open_file(file_name);
	map = read_file(fd);
	ft_printf("%s\n", map);
	exit(1);
	return (map);
}
