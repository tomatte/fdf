/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:16:04 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/26 14:16:22 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_pow(int num, int power)
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

int	hex_char_to_int(char h)
{
	if (ft_isalpha(h))
		return (h - 87);
	return (h - 48);
}

int	validate_hex(char **hex)
{
	int	val;
	int	i;

	val = 1;
	if (**hex == '-')
	{
		(*hex)++;
		val = -1;
	}
	if (!ft_strncmp(*hex, "0x", 2) || !ft_strncmp(*hex, "0X", 2))
	{
		(*hex) += 2;
	}
	if (!**hex)
		return (0);
	i = 0;
	while ((*hex)[i])
	{
		if (!ft_strchr(HEXMAP, ft_tolower((*hex)[i])))
			return (0);
		i++;
	}
	return (val);
}

int	convert(char *hex)
{
	int	len;
	int	i;
	int	aux;
	int	number;

	if (!hex)
		return (0);
	len = ft_strlen(hex);
	aux = len;
	number = 0;
	i = -1;
	while (++i < len)
	{
		number += hex_char_to_int(ft_tolower(hex[i])) * ft_pow(16, --aux);
	}
	return (number);
}

int	ft_hex_to_int(char *hex)
{
	return (validate_hex(&hex) * convert(hex));
}
