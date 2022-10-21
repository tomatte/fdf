#include "fdf.h"

void	asign_values1(t_line *line_data)
{
	line_data->w = line_data->x2 - line_data->x ;
    line_data->h = line_data->y2 - line_data->y ;
    line_data->dx1 = 0;
    line_data->dy1 = 0; 
    line_data->dx2 = 0; 
    line_data->dy2 = 0;
	line_data->numerator = 0;
    line_data->longest = ft_abs(line_data->w);
    line_data->shortest = ft_abs(line_data->h);
}

void	asign_values2(t_line *line_data)
{
    if (line_data->w < 0)
    {
        line_data->dx1 = -1;
        line_data->dx2 = -1 ;    
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
        line_data->longest = ft_abs(line_data->h) ;
        line_data->shortest = ft_abs(line_data->w) ;
        if (line_data->h < 0)
            line_data->dy2 = -1;
        else if (line_data->h > 0)
            line_data->dy2 = 1;
        line_data->dx2 = 0;           
    }
}

void    line(t_data *img, t_line line_data)
{
	int	i;

	asign_values1(&line_data);
	asign_values2(&line_data);
    i = 0;
    while (i++ <= line_data.longest)
    {
        my_mlx_pixel_put(img, line_data.x, line_data.y, 0x00FF0000) ;
        line_data.numerator += line_data.shortest ;
        if (line_data.numerator >= line_data.longest)
        {
            line_data.numerator -= line_data.longest ;
            line_data.x += line_data.dx1 ;
            line_data.y += line_data.dy1 ;
        }
        else
        {
            line_data.x += line_data.dx2 ;
            line_data.y += line_data.dy2 ;
        }
    }
}
