#include "../fdf.h"

static void	draw_between_numbers(int lines, int columns, char *map)
{
	
}

void	draw_map(t_data *img, char *map)
{
	int	lines;
	int	columns;

	lines = get_map_lines(map);
	ft_printf("lines: %d\n", lines);
	columns = get_map_columns(map);
	ft_printf("columns: %d\n", columns);
	draw_between_numbers(lines, columns, map);
}
