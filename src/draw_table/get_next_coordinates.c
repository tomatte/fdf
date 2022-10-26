#include "../fdf.h"

int find_number(char **str)
{
    int num;

    while (**str == ' ' || **str == '\t')
        (*str)++;
    if (ft_isdigit(**str))
    {
        num = ft_atoi(*str);
        while (ft_isdigit(**str))
            (*str)++;
        return (num);
    }
    return (-1);
}

int get_line_size(char *map_line)
{
    int i;

    if (!map_line)
        return (0);
    i = 0;
    while (find_number(&map_line) >= 0)
        i++;
    return (i);
}

int	*get_int_array(int line_size)
{
	int	*coordinates;
	int	i;

	coordinates = ft_calloc(line_size + 1, sizeof(int));
	if (!coordinates)
		return (NULL);
	coordinates[0] = line_size + 1;
	return (coordinates);
}

int *get_next_coordinates(int fd)
{
    char	*map_line;
    int		line_size;
    int		*coordinates;

    map_line = get_next_line(fd);
    line_size = get_line_size(map_line);
    coordinates = get_int_array(line_size);
}

int main(void)
{
	// TESTS //

	//--- find_number() ---//
    int num;
	char	*str;

	ft_printf("FIND_NUMBER FUNCTION TEST:\n");
	str = ft_strdup(" 89 100 ");
    num = find_number(&str);
	ft_printf("res == 89:\t%d\n", num);
    num = find_number(&str);
	ft_printf("res == 100:\t%d\n", num);
	str = ft_strdup("  t2 -10");
    num = find_number(&str);
	ft_printf("res == -1:\t%d\n", num);
	num = find_number(&str);
	ft_printf("res == -1:\t%d\n", num);
	ft_printf("-------------------\n");
	//--------------------------------//

	int	size;
	ft_printf("GET_LINE_SIZE FUNCTION TEST:\n");
	size = get_line_size(" 0 0 10 10 20 10 0 0");
	ft_printf("res == 8:\t%d\n", size);
	size = get_line_size(" 50 50 50 0");
	ft_printf("res == 4:\t%d\n", size);
	size = get_line_size("50 50 0");
	ft_printf("res == 3:\t%d\n", size);
	size = get_line_size("0 0");
	ft_printf("res == 2:\t%d\n", size);
	size = get_line_size("t0 20");
	ft_printf("res == 0:\t%d\n", size);
}