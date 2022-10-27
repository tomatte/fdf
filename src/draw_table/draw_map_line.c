#include "../fdf.h"

int get_x(int l_index, int c_index)
{

}

int get_y(int l_index, int c_index)
{

}

void    put_line(t_data *img, int l_index, int c_index)
{

}

void    put_pixel(t_data *img, int l_index, int c_index)
{

}

int    draw_map_line(t_data *img, int fd, int l_index)
{
    char    *map_line;
    int     *coordinates;
    int     c_index;

    coordinates = get_next_coordinates(fd);
    c_index = 0;
    put_lines(img, coordinates, l_index);
}
