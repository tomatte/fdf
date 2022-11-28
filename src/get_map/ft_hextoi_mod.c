/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:16:36 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/27 23:21:02 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	hex_char_to_int(char c)
{
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	else if (c >= 'a' && c <= 'f')
		return (c - 87);
	else if (ft_isdigit(c))
		return (c - 48);
	else
		return (-1);
}

static int	hex_validate(char **hex)
{
	if (!**hex)
		return (0);
	if (ft_strncmp(*hex, "0x", 2) && ft_strncmp(*hex, "0X", 2))
		return (0);
	(*hex) += 2;
	if (hex_char_to_int(**hex) < 0)
		return (0);
	return (1);
}

//we get to the end of the hex then walk back the pointer converting to int
int	ft_hextoi_mod(char **hex)
{
	int	num;
	int	sign;

	if (!hex_validate(hex))
		return (0);
	sign = 1;
	num = 0;
	while (ft_isspace(**hex))
		(*hex)++;
	if (**hex == '-')
		sign *= -1;
	if (ft_issign(**hex))
		(*hex)++;
	while (hex_char_to_int(**hex) >= 0)
	{
		num = num * 16 + hex_char_to_int(**hex);
		(*hex)++;
	}
	return (num * sign);
}
