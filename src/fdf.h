#ifndef FDF_H
# define FDF_H

	#include <mlx.h>
	#include "../libft/libftprintf.h"
	#include <fcntl.h>

	# define RED 0x00FF0000
	# define MAX_FILE_SIZE 4096
	# define TILE_WIDTH 20
	# define TILE_HEIGHT 10

	typedef struct  s_img
	{
		void    *mlx;
		void    *window;
		void	*img;
		int     width;
		int     height;
		int		bpp;
		int		line_length;
		int     endian;
		char    *addr;
	}			    t_img;

	typedef struct  s_line
	{
		int x;
		int y;
		int x2;
		int y2;
		int w;
		int h;
		int dx1;
		int dy1;
		int dx2;
		int dy2;
		int longest;
		int shortest;
		int proportion;
	}               t_line;

	typedef struct  s_tile
	{
		int	x;
		int	y;
		int width;
		int height;
	}				t_tile;

	typedef struct	s_map
	{
		char	*map;
		int		columns;
		int		lines;
	}				t_map;

	typedef struct	s_data
	{
		t_img	*img;
		t_line	*line;
		t_tile	*tile;
		t_map	*map;
	}				t_data;

	//print an error message and exit program
	void	error_exit(char *error_message);

	// --- Line ---
	void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
	void    draw_line(t_img *img, t_line line_data);
	void    asign_values(t_line *line_data);
	t_line	line_coordinates(int x, int y, int x2, int y2);

	// --- READ_MAP --- //
	char    *get_map(char *file_name);
	char	*read_file(int fd);

	// --- DRAW_MAP --- //
	void	draw_map(t_img *img, char *map);
	int		get_map_columns(char *map);
	int		get_map_lines(char *map);
	void	draw_isometric_line(t_img *img, t_line line);
	
	//pass the line and column as argument
	//and the function will return the number of that location
	int	get_number(int line, int column, char *text);

	//clear memory
	void	mem_clear(void **p);

#endif