#include "../fdf.h"

static void	draw_between_lines(t_img *img, char *map, int i, int j)
{
	//get item i, j and ++i, j;
	//draw_isometric_line();
}

/* static void	draw(t_img *img, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->lines)
	{
		j = 0;
		while (++j < map->columns)
		{
			draw_between_columns(img, map, i, j);
		}
		draw_between_lines(img, map, i, j);
	}
	ft_printf("drawww\n");
} */

static t_line	new_line(int x, int y, int x2, int y2)
{
	t_line	line;

	line.x = x;
	line.y = y;
	line.x2 = x2;
	line.y2 = y2;
	return (line);
}

void	draw_map(t_img *img, char *map_str)
{
	t_map	map;
	t_line	line;

	map.map = map_str;
	map.lines = get_map_lines(map.map);
	map.columns = get_map_columns(map.map);
	ft_printf("%s\n", map.map);

	int	i = 1;
	int	j = 1;
	while (i < 20)
	{
		while (j < 50)
		{
			draw_isometric_line(img, new_line(i, j, i, j + 1));
			draw_isometric_line(img, new_line(i, j, i + 1, j));
			j++;
		}
		j = 1;
		i++;
	}
	

	//draw(img, &map);
}
