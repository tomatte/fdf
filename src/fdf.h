/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:45:58 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 12:47:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libftprintf.h"
# include <fcntl.h>
# define RED 0x00FF0000
# define DEFAULT_COLOR 0x000000FF
# define MAX_FILE_SIZE 4096
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768
# define TILE_WIDTH 40
# define TILE_HEIGHT 35
# define ESC_KEY 65307
# define MINUS_KEY 45
# define PLUS_KEY 61
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364

typedef struct s_img
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*map;
	int		proportion;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
	char	*addr;
}			t_img;

typedef struct s_line
{
	int	x;
	int	y;
	int	x2;
	int	y2;
	int	w;
	int	h;
	int	dx1;
	int	dy1;
	int	dx2;
	int	dy2;
	int	longest;
	int	shortest;
	int	proportion;
	int	color;
}	t_line;

typedef struct s_tile
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_tile;

typedef struct s_map
{
	char	*map;
	int		columns;
	int		lines;
	int		tile_width;
	int		tile_height;
}	t_map;

typedef struct s_position
{
	int	i;
	int	j;
	int	depth;
	int	color;
	int	i2;
	int	j2;
	int	depth2;
	int	color2;
}	t_position;

	// ---- new structure ----
typedef struct s_dot
{
	int		depth;
	int		color;
	void	*front;
	void	*down;
}	t_dot;
//------------------------

//print an error message and exit program
void	error_exit(char *error_message);

// --- Line ---
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_line(t_img *img, t_line line_data);
void	asign_values(t_line *line_data);
t_line	line_coordinates(int x, int y, int x2, int y2);

// --- READ_MAP --- //
char	*get_map(char *file_name);
char	*read_file(int fd);

// --- DRAW_MAP --- //
void	draw_map(t_img *img, char *map);
int		get_map_columns(char *map);
int		get_map_lines(char *map);
void	draw_isometric_line(t_img *img, t_map *map, t_position position);
void	put_isometric_pixel(t_img *img, int x, int y, t_map *map);
int		get_depth(int depth, t_map *map, t_img *img);
void	change_depth(t_img *img);
void	calculate_tile_size(t_img *img, t_map *map);

//pass the line and column as argument
//and the function will return the number of that location
int		get_number(int line, int column, char *text);

//clear memory
void	mem_clear(void **p);

//color
int		get_color(int line, int column, char *text);
int		ft_hextoi(char *hex);

//hooks
void	close_window_x(t_img *img);
void	move_image(t_img *img);

//image
void	window_minimum_size(t_img *img);

//ft_hextoi modified to walk with pointer
int		ft_hextoi_mod(char **hex);

int		ft_atoi_mod(char **nptr);

//dot functions
void	get_first(t_dot **dots, t_dot **first, t_dot **current, char **map);
void	get_next_dot(t_dot **current, t_dot **up, char **map);
t_dot	*get_map_values(char *map);
void	next_line(t_dot **first, t_dot **current, t_dot **up, char **map);

int		extract_color(char **map);
#endif