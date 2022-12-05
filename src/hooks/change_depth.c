/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_depth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:33:30 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/05 23:22:47 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	change(int key_code, t_img *img)
{
	static int	proportion = TILE_HEIGHT >> 1;
	t_img		*old_img;

	if (!(key_code == MINUS_KEY) && !(key_code == PLUS_KEY))
		return (0);
	if (key_code == MINUS_KEY)
		proportion++;
	else if (key_code == PLUS_KEY)
		proportion--;
	old_img = img->img;
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	img->proportion = proportion;
	draw_map(img, img->map);
	mlx_destroy_image(img->mlx, old_img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
}

void	change_depth(t_img *img)
{
	mlx_key_hook(img->window, change, img);
}
