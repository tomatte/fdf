/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:59:06 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 17:16:47 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	esc_close(int key_code, t_img *img)
{
	if (key_code == ESC_KEY)
	{
		ft_printf("Program closed.\n");
		exit(0);
	}
	return (0);
}

static int	move_img(int key_code, t_img *img)
{
	static int	x = 0;
	static int	y = 0;
	int			num;

	num = 30;
	if (key_code == ARROW_UP)
		y -= num;
	else if (key_code == ARROW_LEFT)
		x -= num;
	else if (key_code == ARROW_RIGHT)
		x += num;
	else if (key_code == ARROW_DOWN)
		y += num;
	else
		return (0);
	mlx_put_image_to_window(img->mlx, img->window, img->img, x, y);
	return (0);
}

int	key_hooks(int key_code, t_img *img)
{
	esc_close(key_code, img);
	move_img(key_code, img);
	return (0);
}
