/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:14:59 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 00:08:41 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	free_dots(t_dot *dots)
{
	t_dot		*aux;
	t_dot		*first;


	first = dots;
	aux = NULL;
	while (dots)
	{
		if (dots->front)
			aux = (t_dot *) dots->front;
		else
			aux = NULL;
		free(dots);
		dots = NULL;
		if (aux)
			dots = aux;
		if (!dots && first->down)
		{
			dots = (t_dot *) first->down;
			first = dots;
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
	exit(0);
}
