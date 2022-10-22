#ifndef FDF_H
# define FDF_H

    #include <mlx.h>
    #include "./libft/libftprintf.h"

    typedef struct  s_data
    {
        void    *mlx;
        void    *window;
        void	*img;
        int     width;
        int     height;
        int		bpp;
        int		size_line;
        int     endian;
        char    *addr;
    }			    t_data;

    typedef struct  s_line
    {
        int x;
        int y;
        int x2;
        int y2;
        int w;
        int h;
        int dx1;
        int dy1;
        int dx2;
        int dy2;
        int longest;
        int shortest;
        int numerator;
    }               t_line;

    void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
    void    draw_line(t_data *img, t_line line_data);

#endif