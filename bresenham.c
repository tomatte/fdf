#include "fdf.h"

/* typedef struct  t_line
{
    int w;
    int h;
    int dx1;
    int dy1;
    int dx2;
    int dy2;
    int longest;
    int shortest;
}               s_line; */

void    bresenham(t_data *img, int x,int y,int x2, int y2)
{
    int w;
    int h;
    int dx1;
    int dy1;
    int dx2;
    int dy2;
    int longest;
    int shortest;
    int numerator;
    int i;

    w = x2 - x ;
    h = y2 - y ;
    dx1 = 0;
    dy1 = 0; 
    dx2 = 0; 
    dy2 = 0;
    if (w < 0)
    {
        dx1 = -1;
        dx2 = -1 ;    
    }
    else if (w > 0)
    {
        dx1 = 1;
        dx2 = 1;
    }
    if (h < 0)
        dy1 = -1;
    else if (h > 0)
        dy1 = 1;
    longest = ft_abs(w);
    shortest = ft_abs(h);
    if (longest <= shortest)
    {
        longest = ft_abs(h) ;
        shortest = ft_abs(w) ;
        if (h < 0)
            dy2 = -1;
        else if (h > 0)
            dy2 = 1;
        dx2 = 0;           
    }
    numerator = 0;
    i = 0;
    while (i++ <= longest)
    {
        my_mlx_pixel_put(img, x, y, 0x00FF0000) ;
        numerator += shortest ;
        if (numerator >= longest)
        {
            numerator -= longest ;
            x += dx1 ;
            y += dy1 ;
        }
        else
        {
            x += dx2 ;
            y += dy2 ;
        }
    }
}
