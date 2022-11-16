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

void	draw_isometric_line(t_img *img, t_line line)
{
	t_tile	tile;

	tile = new_tile(line.x, line.y);
	line.x = get_pixel_x(img, &tile);
	line.y = get_pixel_y(img, &tile);
	tile.x = line.x2;
	tile.y = line.y2;
	line.x2 = get_pixel_x(img, &tile);
	line.y2 = get_pixel_y(img, &tile);
/* 	ft_printf("test 1: \n");
	ft_printf("linex: %d\n", line.x);
	ft_printf("liney: %d\n", line.y);
	ft_printf("linex2: %d\n", line.x2);
	ft_printf("liney2: %d\n", line.y2); */
	draw_line(img, line);
}