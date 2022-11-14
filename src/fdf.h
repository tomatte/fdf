#ifndef FDF_H
# define FDF_H

	#include <mlx.h>
	#include "../libft/libftprintf.h"
	#include <fcntl.h>

	# define RED 0x00FF0000
	# define MAX_FILE_SIZE 4096

	typedef struct  s_data
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
	}			    t_data;

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
		int	**lines;
		int	**columns;
		int	line_qty;
		int	column_qty;
		int	line_size;
		int	column_size;
	}				t_map;

	//print an error message and exit program
	void	error_exit(char *error_message);

	// --- Line ---
	void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
	void    draw_line(t_data *img, t_line line_data);
	void    asign_values(t_line *line_data);
	t_line	line_coordinates(int x, int y, int x2, int y2);

	// --- READ_MAP --- //
	char    *get_map(char *file_name);
	char	*read_file(int fd);

	// --- DRAW_MAP --- //
	
	//find a number in a text and returns it as an int
	int	get_number(int line, int column, char *text);

#endif