/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:14:59 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 09:17:25 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	free_dots(t_dot *dots)
{
	t_dot		*aux;
	t_dot		*down;

	aux = (t_dot *) dots->front;
	down = (t_dot *) dots->down;
	while (dots)
	{
		mem_clear((void *) &dots);
		if (aux)
		{
			dots = aux;
			aux = (t_dot *) dots->front;
		}
		else if (down)
		{
			dots = down;
			aux = (t_dot *) dots->front;
			down = (t_dot *) dots->down;
		}
	}
}

void	finish_program(t_img *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->window);
	mlx_destroy_display(img->mlx);
	free_dots(img->dots);
	free(img->map);
	free(img->mlx);
	exit(0);
}
