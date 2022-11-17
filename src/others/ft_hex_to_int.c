#include "../fdf.h"
//tested!!!
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

//tested
int	ft_hex_to_int(char *hex)
{
	return (validate_hex(&hex) * convert(hex));
}

// int	main(void)
// {
// 	ft_printf("expected: 0 // got: %d\n", ft_hex_to_int("0"));
// 	ft_printf("expected: 16 // got: %d\n", ft_hex_to_int("10"));
// 	ft_printf("expected: 15 // got: %d\n", ft_hex_to_int("f"));
// 	ft_printf("expected: 14 // got: %d\n", ft_hex_to_int("e"));
// 	ft_printf("expected: 13 // got: %d\n", ft_hex_to_int("d"));
// 	ft_printf("expected: 12 // got: %d\n", ft_hex_to_int("c"));
// 	ft_printf("expected: 11 // got: %d\n", ft_hex_to_int("b"));
// 	ft_printf("expected: 10 // got: %d\n", ft_hex_to_int("a"));
// 	ft_printf("expected: 2730 // got: %d\n", ft_hex_to_int("0XaAa"));
// 	ft_printf("expected: -2730 // got: %d\n", ft_hex_to_int("-aaA"));
// 	ft_printf("expected: 3003 // got: %d\n", ft_hex_to_int("bbb"));
// 	ft_printf("expected: -3003 // got: %d\n", ft_hex_to_int("-bbb"));
// 	ft_printf("expected: 3276 // got: %d\n", ft_hex_to_int("ccc"));
// 	ft_printf("expected: -3276 // got: %d\n", ft_hex_to_int("-ccc"));
// 	ft_printf("expected: 3549 // got: %d\n", ft_hex_to_int("Ddd"));
// 	ft_printf("expected: -3549 // got: %d\n", ft_hex_to_int("-ddd"));
// 	ft_printf("expected: 3822 // got: %d\n", ft_hex_to_int("eee"));
// 	ft_printf("expected: -3822 // got: %d\n", ft_hex_to_int("-eEe"));
// 	ft_printf("expected: 4095 // got: %d\n", ft_hex_to_int("fff"));
// 	ft_printf("expected: -4095 // got: %d\n", ft_hex_to_int("-fff"));
// 	ft_printf("expected: 2748 // got: %d\n", ft_hex_to_int("abc"));
// 	ft_printf("expected: -2748 // got: %d\n", ft_hex_to_int("-abc"));
// 	ft_printf("expected: 11259375 // got: %d\n", ft_hex_to_int("abcdef"));
// 	ft_printf("expected: -11259375 // got: %d\n", ft_hex_to_int("-aBcdef"));
// 	ft_printf("expected: 0 // got: %d\n", ft_hex_to_int("-xabcdef"));
// 	ft_printf("expected: -9 // got: %d\n", ft_hex_to_int("-0x9"));
// 	ft_printf("expected: 9 // got: %d\n", ft_hex_to_int("0x9"));
// 	ft_printf("expected: 11259375 // got: %d\n", ft_hex_to_int("0xabcDEF"));
// 	return (0);
// }