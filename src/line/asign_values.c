#include "../fdf.h"

static void	initialize_line_struct(t_line *line_data)
{
	line_data->w = line_data->x2 - line_data->x;
    line_data->h = line_data->y2 - line_data->y;
    line_data->dx1 = 0;
    line_data->dy1 = 0; 
    line_data->dx2 = 0; 
    line_data->dy2 = 0;
	line_data->proportion = 0;
    line_data->longest = ft_abs(line_data->w);
    line_data->shortest = ft_abs(line_data->h);
}

static void	decide_xy_direction(t_line *line_data)
{
    if (line_data->w < 0)
    {
        line_data->dx1 = -1;
        line_data->dx2 = -1;
    }
    else if (line_data->w > 0)
    {
        line_data->dx1 = 1;
        line_data->dx2 = 1;
    }
    if (line_data->h < 0)
        line_data->dy1 = -1;
    else if (line_data->h > 0)
        line_data->dy1 = 1;
    if (line_data->longest <= line_data->shortest)
    {
        line_data->longest = ft_abs(line_data->h);
        line_data->shortest = ft_abs(line_data->w);
        if (line_data->h < 0)
            line_data->dy2 = -1;
        else if (line_data->h > 0)
            line_data->dy2 = 1;
        line_data->dx2 = 0;           
    }
}

void    asign_values(t_line *line_data)
{
    initialize_line_struct(line_data);
    decide_xy_direction(line_data);
}
