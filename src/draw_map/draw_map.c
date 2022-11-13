#include "../fdf.h"

int	open_map(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	return (fd);
}

static void	draw_vertically(t_tile *current, t_tile next)
{
	
	*current = next;
}

void	draw_map(char *file_name)
{
	t_tile	current;
	t_tile	next;
	int		fd;
	int		y;

	fd = open_map(file_name);
	current = get_tile_data(fd);
	current.y = 0;
	draw_horizontally(current);
	while (1)
	{
		next = get_tile_data(fd);
		if (!next)
			return ;
		next.y = current.y + 1;
		draw_horizontally(next);
		draw_vertically(&current, next);
	}
}
