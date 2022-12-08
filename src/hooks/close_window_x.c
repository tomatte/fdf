/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:41 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/08 17:44:49 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_x(t_img *img)
{
	ft_printf("\nProgram closed.\n");
	finish_program(img);
	return (0);
}

static int	minimize_window(t_img *img)
{
	mlx_clear_window(img->mlx, img->window);
	mlx_put_image_to_window(img->mlx, img->window, img->img, img->x, img->y);
	return (0);
}

void	close_window_x(t_img *img)
{
	mlx_hook(img->window, 17, 1L << 17, close_x, img);
	mlx_hook(img->window, 9, 1L << 21, minimize_window, img);
}
