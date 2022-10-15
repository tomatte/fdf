#ifndef FDF_H
# define FDF_H

    #include <mlx.h>
    #include <stdlib.h>

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

#endif