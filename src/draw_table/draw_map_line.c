#include "../fdf.h"

static t_line	get_line_data(int l_index, int c)
{
	t_line	line_data;
	int		s;

	s = 20;
	line_data.x = c * s;
	line_data.y = l_index * s;
	line_data.x2 = (c + 1) * s;
	line_data.y2 = (l_index + 1) * s;
	return (line_data);
}

static void	put_pixel(img, int l_index, int c)
{
	int	x;
	int	y;
	int	s;

	x = c * s;
	y = l_index * s;
	my_mlx_pixel_put(img, x, y, RED);
}

static void	put_lines(t_data *img, int *coordinates, int l_index)
{
	int		c;
	int		s;

	s = 20;
	c = 0;
    while (++c < coordinates[0])
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
    put_lines(img, coordinates, l_index);
}
