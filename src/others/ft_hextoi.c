#include "../fdf.h"
//tested!!!
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
	int	len;
	int	i;

	if (!hex_validation(&hex))
		return (-1);
	while (*hex && hex_char_to_int(*hex) >= 0)
		hex++;
	number = 0;
	i = 0;
	while (hex_char_to_int(*(--hex)) >= 0)
		{	
			number += hex_char_to_int(*hex) * ft_pow(16, i++);
		}
	return (number);
}



// int	main(void)
// {
// 	ft_printf("expected: 0 // got: %d\n", ft_hextoi("0x0"));
// 	ft_printf("expected: 16 // got: %d\n", ft_hextoi("0x10"));
// 	ft_printf("expected: 15 // got: %d\n", ft_hextoi("0xf"));
// 	ft_printf("expected: 14 // got: %d\n", ft_hextoi("0xe"));
// 	ft_printf("expected: 13 // got: %d\n", ft_hextoi("0xd"));
// 	ft_printf("expected: 12 // got: %d\n", ft_hextoi("0xc"));
// 	ft_printf("expected: 11 // got: %d\n", ft_hextoi("0xb"));
// 	ft_printf("expected: 10 // got: %d\n", ft_hextoi("0xa"));
// 	ft_printf("expected: 2730 // got: %d\n", ft_hextoi("0XaAa"));
// 	ft_printf("expected: -1 // got: %d\n", ft_hextoi("-aaA"));
// 	ft_printf("expected: 3003 // got: %d\n", ft_hextoi("0xbbb"));
// // 	ft_printf("expected: -3003 // got: %d\n", ft_hex_to_int("-bbb"));
// // 	ft_printf("expected: 3276 // got: %d\n", ft_hex_to_int("ccc"));
// // 	ft_printf("expected: -3276 // got: %d\n", ft_hex_to_int("-ccc"));
// // 	ft_printf("expected: 3549 // got: %d\n", ft_hex_to_int("Ddd"));
// // 	ft_printf("expected: -3549 // got: %d\n", ft_hex_to_int("-ddd"));
// // 	ft_printf("expected: 3822 // got: %d\n", ft_hex_to_int("eee"));
// // 	ft_printf("expected: -3822 // got: %d\n", ft_hex_to_int("-eEe"));
// // 	ft_printf("expected: 4095 // got: %d\n", ft_hex_to_int("fff"));
// // 	ft_printf("expected: -4095 // got: %d\n", ft_hex_to_int("-fff"));
// // 	ft_printf("expected: 2748 // got: %d\n", ft_hex_to_int("abc"));
// // 	ft_printf("expected: -2748 // got: %d\n", ft_hex_to_int("-abc"));
// // 	ft_printf("expected: 11259375 // got: %d\n", ft_hex_to_int("abcdef"));
// // 	ft_printf("expected: -11259375 // got: %d\n", ft_hex_to_int("-aBcdef"));
// // 	ft_printf("expected: 0 // got: %d\n", ft_hex_to_int("-xabcdef"));
// 	ft_printf("expected: -1 // got: %d\n", ft_hextoi("-0x9"));
// 	ft_printf("expected: 9 // got: %d\n", ft_hextoi("0x9"));
// 	ft_printf("expected: 11259375 // got: %d\n", ft_hextoi("0xabcDEF"));
// 	ft_printf("expected: 5: %d\n", ft_hextoi("0x5"));
// 	return (0);
// }