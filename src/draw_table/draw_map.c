#include "../fdf.h"

static int    open_map(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	return (fd);
}

void    draw_map(t_data *img, char *file_name)
{
	int     fd;
	int     line;
	int     *previous_coordinates;
	int		*current_coordinates;

	fd = open_map(file_name);
	line = 0;
	previous_coordinates = draw_map_line(img, fd, line);
	if (!previous_coordinates)
		return ;
	while (1)
	{
		line++;
		current_coordinates = draw_map_line(img, fd, line);
		if (!current_coordinates)
			return ;
		draw_map_column(img, previous_coordinates, current_coordinates, line);
		previous_coordinates = current_coordinates;
	}
}


/* 
--- draw_table ---
------------------

int fd = open_map("file_name");
char *map_line = read_map_line(fd);
int *before_coordiantes = get_int_coordinates(map_line);
int *current_coordinates = get_int_coordinates(map_line);
é necessário armazenar as coordenadas da linha atual e da linha anterior
desse modo seremos capaz de analisar se as suas colunas formam linhas
draw_map_line(img, line_coordinates);
	- line_coordinates[0] //array size
	- while(i++)
		if !line_coordinates[i]
			draw_a_pixel
		else if (!line_coordinates[i] && !line_coordinates[i + 1])
			draw_a_line


put_line()
{
	if (!previous_coordinate[c_line - 1] || !current_coordinate[l_line])
		return ;
	//draw line between them
}

//current_line_coordinates[0] == number of items in array
draw_map_line(img, current_line_coordinates, l_index)
{
	int     x;
	int     y;
	int     c_index;

	c_index = 0;
	while (++c_index < current_line_coordinates[0])
	{
		put_line();
		put_pixel();
	}
}

draw_map_column(img, previous_line_coordinates, current_line_coordinates, index)
{

}

	- */