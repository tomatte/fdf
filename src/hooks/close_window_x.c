/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:15:41 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 23:47:02 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_x(t_img *img)
{
	ft_printf("\nProgram closed.\n");
	finish_program(img);
	return (0);
}

void	close_window_x(t_img *img)
{
	mlx_hook(img->window, 17, 1L << 17, close_x, img);
}
