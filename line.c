#include "fdf.h"

void	draw_line(t_data *img, int x1, int y1, int x2, int y2)
{
	int	width;
	int	height;
	int	lower;
	int	r;
	int	times;
	
	width = x2 - x1;
	height = y2 - y1;
	if (x2 > y2)
	{
		r = x2 / y2;
		lower = y2;
	}
	else
	{
		r = y2 / x2;
		lower = x2;
	}
	times = r;
	while (lower >= 0)
	{
		while (times > 0)
		{
			if (x1 <= x2)
				my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
			x1++;
			times--;
		}
		y1++;
		if (lower > 0 && y1 <= y2)
			my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
		lower--;
		times = r;
	}
}