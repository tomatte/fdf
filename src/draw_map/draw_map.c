#include "../fdf.h"

static t_line	new_line(int x, int y, int x2, int y2)
{
	t_line	line;

	line.x = x;
	line.y = y;
	line.x2 = x2;
	line.y2 = y2;
	return (line);
}

static t_map	get_map_values(char *map_str)
{
	t_map	map;

	map.map = map_str;
	map.lines = get_map_lines(map.map);
	map.columns = get_map_columns(map.map);
	return (map);
}

static void	draw_map_columns(t_img *img, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= map->lines)
	{
		j = -1;
		while (++j < map->columns)
		{
			draw_isometric_line(img, new_line(i, j, i, j + 1));
		}
	}
}

static void	draw_map_lines(t_img *img, t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j <= map->lines)
	{
		i = -1;
		while (++i < map->columns)
		{
			ft_printf("i: %d\n", i);
			ft_printf("j: %d\n", j);
			draw_isometric_line(img, new_line(i, j, i + 1, j));
		}
	}
}

void	draw_map(t_img *img, char *map_str)
{
	t_map	map;
	t_line	line;

	
	map = get_map_values(map_str);
	ft_printf("columns: %d\n", map.columns);
	draw_map_columns(img, &map);
	draw_map_lines(img, &map);
	//draw(img, &map);
}
