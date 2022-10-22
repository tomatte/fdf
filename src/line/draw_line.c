#include "../fdf.h"

void	walk_longest(t_line *line_data)
{
	line_data->proportion -= line_data->longest;
	line_data->x += line_data->dx1;
	line_data->y += line_data->dy1;
}

void	walk_both(t_line *line_data)
{
	line_data->x += line_data->dx2;
	line_data->y += line_data->dy2;
}

void	walk_pixel(t_line *line_data)
{
        if (line_data->proportion >= line_data->longest)
			walk_longest(line_data);
        else
			walk_both(line_data);
}

void    draw_line(t_data *img, t_line line_data)
{
	int	i;

    asign_values(&line_data);
    i = 0;
    while (i++ <= line_data.longest)
    {
        my_mlx_pixel_put(img, line_data.x, line_data.y, 0x00FF0000);
        line_data.proportion += line_data.shortest;
		walk_pixel(&line_data);
    }
}
