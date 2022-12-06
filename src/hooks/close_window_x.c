/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:41 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 12:46:53 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_x(t_img *img)
{
	mlx_destroy_window(img->mlx, img->window);
	ft_printf("\nProgram closed\n");
	exit(0);
	return (0);
}

void	close_window_x(t_img *img)
{
	mlx_hook(img->window, 17, 1L << 17, close_x, img);
}
