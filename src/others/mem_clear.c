#include "../fdf.h"

void	mem_clear(void **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}
