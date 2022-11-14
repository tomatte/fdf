#include "../fdf.h"

static void	draw_between_columns(t_data *img, char *map, int i, int j)
{
	//get item i, j  and i, ++j;
	draw_isometric_line();
}

static void	draw_between_lines(t_data *img, char *map, int i, int j)
{
	//get item i, j and ++i, j;
	draw_isometric_line();
}

static void	draw(t_data *img, int lines, int columns, char *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < lines)
	{
		j = 0;
		while (++j < columns)
		{
			draw_between_columns(img, map, i, j);
		}
		draw_between_lines(img, map, i, j);
	}
}

void	draw_map(t_data *img, char *map)
{
	int	lines;
	int	columns;

	lines = get_map_lines(map);
	columns = get_map_columns(map);
	draw(img, lines, columns, map);
}
