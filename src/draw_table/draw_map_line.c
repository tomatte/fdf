#include "../fdf.h"

static t_line	get_line_data(int l_index, int column)
{
	t_line	line_data;
	int		space;

	space = 20;
	line_data.x = column * space;
	line_data.y = l_index * space;
	line_data.x2 = (column + 1) * space;
	line_data.y2 = l_index * space;
	return (line_data);
}

static void	put_pixel(t_data *img, int l_index, int column)
{
	int	x;
	int	y;
	int	space;

	space = 20;
	x = column * space;
	y = l_index * space;
	my_mlx_pixel_put(img, x, y, 0x00FF0000);
}

static void	put_lines(t_data *img, int *coordinates, int l_index)
{
	int		c;
	int		s;

	if (!coordinates)
		return ;
	s = 20;
	c = 0;
    while (++c < coordinates[0] - 1)
	{
		if (coordinates[c] && coordinates[c + 1])
			draw_line(img, get_line_data(l_index, c));
		else
			put_pixel(img, l_index, c);
	}
}

int	draw_map_line(t_data *img, int fd, int l_index)
{
    char    *map_line;
    int     *coordinates;

    coordinates = get_next_coordinates(fd);
	if (!coordinates)
		return (0);
    put_lines(img, coordinates, l_index);
	return (1);
}
