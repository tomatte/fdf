#include "../fdf.h"

static int	get_pixel_x(t_img *img, t_tile *tile)
{
	int		pixel_x;

	pixel_x = (tile->y - tile->x ) * (tile->width / 2);
	pixel_x += img->width / 2;
	return (pixel_x);
}

static int	get_pixel_y(t_img *img, t_tile *tile)
{
	int		pixel_y;

	pixel_y = (tile->x + tile->y ) * (tile->height / 2);
	pixel_y += img->height / 2;
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

void	put_isometric_pixel(t_img *img, int x, int y)
{
	t_tile	tile;

	tile = new_tile(x, y);
	x = get_pixel_x(img, &tile);
	y = get_pixel_y(img, &tile);
	my_mlx_pixel_put(img, x, y, RED);
}

void	draw_isometric_line(t_img *img, t_line line, int depth1, int depth2)
{
	t_tile	tile;

	tile = new_tile(line.x, line.y);
	line.x = get_pixel_x(img, &tile);
	line.y = get_pixel_y(img, &tile);
	tile.x = line.x2;
	tile.y = line.y2;
	line.x2 = get_pixel_x(img, &tile);
	line.y2 = get_pixel_y(img, &tile);
	line.y -= depth1 * (tile.height >> 3);
	line.y2 -= depth2 * (tile.height >> 3);
	draw_line(img, line);
}