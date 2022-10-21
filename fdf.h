#ifndef FDF_H
# define FDF_H

    #include <mlx.h>
    #include "./libft/libftprintf.h"

    typedef struct s_data
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
    }			t_data;

    void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
    void	line(t_data *img, int x1, int y1, int x2, int y2);
    void    line(t_data *img, int x,int y,int x2, int y2);

#endif