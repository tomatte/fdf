/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:20:49 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/06 12:21:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	move_img(int key_code, t_img *img)
{
	static int	x = 0;
	static int	y = 0;
	int			num;

	num = 30;
	if (key_code == ARROW_UP && y >= num)
		y -= num;
	else if (key_code == ARROW_LEFT && x >= num)
		x -= num;
	else if (key_code == ARROW_RIGHT && x + num <= img->width)
		x += num;
	else if (key_code == ARROW_DOWN && y + num <= img->height)
		y += num;
	else
		return (0);
	mlx_put_image_to_window(img->mlx, img->window, img->img, x, y);
	return (0);
}

void	move_image(t_img *img)
{
	mlx_key_hook(img->window, move_img, img);
}
