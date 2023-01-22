/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_depth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:23:55 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/22 20:25:34 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	change_depth_value(int key_code, t_img *img)
{
	if (key_code == PLUS_KEY)
		img->depth_mod += 10;
	else
		img->depth_mod -= 10;
}

static int	is_depth_command(int key_code)
{
	if (key_code == PLUS_KEY || key_code == MINUS_KEY)
		return (1);
	else
		return (0);
}

void	change_depth(int key_code, t_img *img)
{
	if (!is_depth_command(key_code))
		return ;
	change_depth_value(key_code, img);
	apply_changes(img);
}
