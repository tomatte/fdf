/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:04:58 by dbrandao          #+#    #+#             */
/*   Updated: 2022/11/26 18:08:50 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_atoi_mod(char **nptr)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '-')
		sign *= -1;
	if (ft_issign(**nptr))
		(*nptr)++;
	while (ft_isdigit(**nptr))
	{
		num = num * 10 + (**nptr - 48);
		(*nptr)++;
	}
	return (num * sign);
}

int	main(int argc, char **argv)
{
	char	*map;
	int		num;

	map = get_map(argv[1]);
	ft_printf("map: \n%s\n\n", map);
	num = ft_atoi_mod(&map);
	ft_printf("num: %d\n", num);
	ft_printf("map: \n%s\n\n", map);
	return (0);
}

//gcc map_struct.c read_file.c ../others/error_exit.c ../others/mem_clear.c ./get_map.c ../../libft/libftprintf.a