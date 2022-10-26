#include "../fdf.h"

int get_line_size(char *map_line)
{
    if (!map_line)
        return (0);
    while ()
}

int *get_next_coordinates(int fd)
{
    char    *map_line;
    int     line_size;
    int     *coordinates;

    map_line = get_next_line(fd);
    line_size = get_line_size(map_line);
    coordinates = alloc_int_array(line_size);

    /* 0 0 20 0 20 0 0 0 20 */
}