#include "../fdf.h"

static int	get_pixel_x(t_img *img, int i, int j)
{
	int		pixel_x;

	pixel_x = (i - j ) * (TILE_WIDTH / 2);
	pixel_x += img->width / 2;
	ft_printf("pixel_x: %d\n", pixel_x);
	return (pixel_x);
}

static int	get_pixel_y(t_img *img, int i, int j, t_map *map)
{
	int		pixel_y;
	int		centralize_map;
	int		map_height;

	pixel_y = (i + j) * (TILE_HEIGHT / 2);
	map_height = (map->columns + map->lines) * (TILE_HEIGHT / 2);
	centralize_map = (img->height / 2) - (map_height / 2);
	pixel_y += centralize_map;
	ft_printf("pixel_y: %d\n", pixel_y);
	return (pixel_y);
}

static t_tile	new_tile(int x, int y)
{
	t_tile	tile;

	tile.x = x;
	tile.y = y;
	tile.width = TILE_WIDTH;
	tile.height = TILE_HEIGHT;
	return (tile);
}

void	put_isometric_pixel(t_img *img, int x, int y, t_map *map)
{
	int	pixel_y;
	int	pixel_x;

	pixel_x = get_pixel_x(img, x, y);
	pixel_y = get_pixel_y(img, x, y, map);
	my_mlx_pixel_put(img, x, y, RED);
}

void	draw_isometric_line(t_img *img, t_map *map, t_position position)
{
	t_line	line;

	line.color = get_color(position.i, position.j, map->map);
	if (line.color == RED)
		line.color = get_color(position.i2, position.j2, map->map);
	line.x = get_pixel_x(img, position.i, position.j);
	line.y = get_pixel_y(img, position.i, position.j, map);
	line.x2 = get_pixel_x(img, position.i2, position.j2);
	line.y2 = get_pixel_y(img, position.i2, position.j2, map);
	line.y -= get_depth(position.i, position.j, map);
	line.y2 -= get_depth(position.i2, position.j2, map);
	draw_line(img, line);
}
