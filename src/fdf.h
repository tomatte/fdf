#ifndef FDF_H
# define FDF_H

    #include <mlx.h>
    #include "../libft/libftprintf.h"
    #include <fcntl.h>

    # define RED 0x00FF0000

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
        int proportion;
    }               t_line;

    void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
    void    draw_line(t_data *img, t_line line_data);
    void    asign_values(t_line *line_data);
    t_line	line_coordinates(int x, int y, int x2, int y2);

    // --- DRAW_TABLE --- //
    int     *get_next_coordinates(int fd);
    int	    draw_map_line(t_data *img, int fd, int l_index);
    void    draw_map(t_data *img, char *file_name);
    int     get_line_size(char *map_line);

#endif