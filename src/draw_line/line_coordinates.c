#include "../fdf.h"

t_line	line_coordinates(int x, int y, int x2, int y2)
{
	t_line	line_data;

	line_data.x = x;
	line_data.y = y;
	line_data.x2 = x2;
	line_data.y2 = y2;
	return (line_data);
}
