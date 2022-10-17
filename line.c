#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	ft_printf("[%d, %d]\n", x, y);
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	line(t_data *img, int x1, int y1, int x2, int y2)
{
	int		less;
	int		i;
	float	fraction;
	float	r;
	if (x2 - x1 == 0)
	{
		r = ft_abs(y2 - y1);
		less = 1;
	}
	else if (y2 - y1 == 0)
	{
		r = ft_abs(x2 - x1);
		less = 1;
	}
	else if (ft_abs(x2 - x1) < ft_abs(y2 - y1))
	{
		less = ft_abs(x2 - x1);
		r = (float) ft_abs(y2 - y1) / ft_abs(x2 - x1);
	}
	else
	{
		less = ft_abs(y2 - y1);
		r = (float) ft_abs(x2 - x1) / ft_abs(y2 - y1);
	}
	ft_printf("r: %d\nless: %d\n", r, less);
	my_mlx_pixel_put(img, x1++, y1, 0x00FF0000);
	//case x greater
	fraction = 0;
	printf("width: %d\n", ft_abs(x2 - x1));
	printf("height: %d\n", ft_abs(y2 - y1));
	printf("less: %d\n", less);
	printf("R: %f\n", r);
	if (ft_abs(x2 - x1) > ft_abs(y2 - y1))
	{
		while (less-- > 0)
		{
			if (y2 > y1)
				my_mlx_pixel_put(img, x1, y1++, 0x00FF0000);
			else
				my_mlx_pixel_put(img, x1, y1--, 0x00FF0000);
			fraction += r - (int) r;
			if (fraction >= 1)
			{
				i = r + 1;
				fraction--;
			}
			else
				i = (int) r;
			while (i-- > 0)
			{
				if (x2 > x1)
					my_mlx_pixel_put(img, x1++, y1, 0x00FF0000);
				else
					my_mlx_pixel_put(img, x1--, y1, 0x00FF0000);
			}
		}
	}
	else
	{
		while (less-- > 0)
		{
			printf("entrou!\n");
			if (x2 > x1)
				my_mlx_pixel_put(img, x1++, y1, 0x00FF0000);
			else
				my_mlx_pixel_put(img, x1--, y1, 0x00FF0000);
			fraction += r - (int) r;
			if (fraction >= 1)
			{
				i = (int) (r + 1);
				fraction--;
			}
			else
				i = (int) r;
			while (i-- > 0)
			{
				if (y2 > y1)
					my_mlx_pixel_put(img, x1, y1++, 0x00FF0000);
				else
					my_mlx_pixel_put(img, x1, y1--, 0x00FF0000);
			}
		}
	}
}

/* 
	TRAÇAR UMA LINHA ENTRE DOIS PONTOS

	PROPRIEDADES:
		- comprimento
		- altura
	A propriedade maior deverá se ajustar à propriedade menor.

	Criar um while(less-- > 0)
		printar o menor (voltando ou avançando?)
		while(greater-- > 0)
			printar maior (voltando ou avançando?)

 */