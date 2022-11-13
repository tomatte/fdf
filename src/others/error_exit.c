#include "../fdf.h"

void	error_exit(char *error_message)
{
	ft_printf("\033[0;31m%s\033[0m", error_message);
	exit(EXIT_FAILURE);
}
