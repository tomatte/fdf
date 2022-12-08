/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:10:56 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 20:17:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	verify_pixel(t_img *img, t_line *line)
{
	if (line->x < 0 || line->y < 0
		|| line->x > img->width || line->y > img->height
		|| line->x2 > img->width || line->y2 > img->height)
	{
		ft_printf("Your coodinates are escaping the image. Program closed.\n");
		finish_program(img);
		exit(0);
	}
}
