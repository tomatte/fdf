#include "../fdf.h"

static char	*join_and_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	result = ft_strjoin(s1, s2);
	mem_clear((void *) &s1);
	mem_clear((void *) &s2);
	return (result);
}

char	*read_file(int fd)
{
	char    *map;
	char	*aux;

	map = NULL;
	while (1)
	{
		aux = get_next_line(fd);
		if (!aux)
			return map;
		map = join_and_free(map, aux);
	}
}
