/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:16:36 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 16:59:47 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_pow(int num, int power)
{
	int	i;
	int	result;

	if (!power)
		return (1);
	result = 1;
	i = 0;
	while (i++ < power)
	{
		result *= num;
	}
	return (result);
}

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

static int	hex_validation(char **hex)
{
	if (ft_strncmp(*hex, "0x", 2) && ft_strncmp(*hex, "0X", 2))
		return (0);
	*hex += 2;
	if (hex_char_to_int(**hex) < 0)
		return (0);
	return (1);
}

int	ft_hextoi(char *hex)
{
	int	number;
	int	i;

	if (!hex_validation(&hex))
		return (-1);
	while (*hex && hex_char_to_int(*hex) >= 0)
		hex++;
	number = 0;
	i = 0;
	while (hex_char_to_int(*(--hex)) >= 0)
		number += hex_char_to_int(*hex) * ft_pow(16, i++);
	return (number);
}
