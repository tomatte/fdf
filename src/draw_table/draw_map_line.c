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

void	put_pixel(t_data *img, int l_index, int column)
{
	int	x;
	int	y;
	int	space;

	space = 20;
	x = column * space;
	y = l_index * space;
	my_mlx_pixel_put(img, x, y, 0x00FF0000);
}

static void	put_lines(t_data *img, int *coordinates, int line)
{
	int		column;
	int		s;

	if (!coordinates)
		return ;
	column = 0;
	while (++column < coordinates[0] - 1)
	{
		if (coordinates[column] && coordinates[column + 1])
			draw_line(img, get_line_data(line, column));
		else
			put_pixel(img, line, column);
	}
}

int	*draw_map_line(t_data *img, int fd, int line)
{
	char    *map_line;
	int     *coordinates;

	coordinates = get_next_coordinates(fd);
	if (!coordinates)
		return (NULL);
	put_lines(img, coordinates, line);
	return (coordinates);
}

/* 
 0000

 1111

 0000
 1111

 2222

 1111
 2222

 3333

 2222
 3333

 ler e desenhar linha x

 while
	ler e desenhar linha x+1

	desenhar coluna com linha x e x+1
	x = x+1
 */