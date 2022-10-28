#include "../fdf.h"

static t_line	get_line_data(int line, int column)
{
	t_line	line_data;
	int		space;

	space = 20;
	line_data.x = column * space;
	line_data.y = line * space;
	line_data.x2 = column * space;
	line_data.y2 = (line + 1) * space;
	return (line_data);
}

static void	put_columns(t_data *img, int *previous, int *current, int line)
{
	int		column;

	if (!current || !previous)
		return ;
	column = 0;
	while (++column < previous[0] || column < current[0])
	{
		if (previous[column] && current[column])
			draw_line(img, get_line_data(line, column));
		else
			put_pixel(img, line, column);
	}
}

void	draw_map_column(t_data *img, int *previous, int *current, int line)
{
	if (!previous || !current)
		return ;
	put_columns(img, previous, current, line - 1);
}
