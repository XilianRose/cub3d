/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_csnx.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 14:50:18 by mstegema      #+#    #+#                 */
/*   Updated: 2023/06/09 15:32:46 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>

int	ft_printf_str(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	if (s == NULL)
		return (ft_printf_str("(null)"));
	i = write(1, s, len);
	if (i != len)
		return (-1);
	return (i);
}

int	ft_printf_char(char c)
{
	int	i;

	i = write(1, &c, 1);
	if (i > 0)
		return (i);
	else
		return (-1);
}

int	ft_printf_nbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		ft_printf_str("-2147483648");
	}
	else if (n < 0)
	{
		ft_printf_char('-');
		ft_printf_nbr(-n);
	}
	else if (n < 10)
	{
		c = '0' + n;
		ft_printf_char(c);
	}
	else
	{
		ft_printf_nbr(n / 10);
		ft_printf_nbr(n % 10);
	}
	return (my_intlen(n));
}

int	ft_printf_uns(unsigned int n, int res)
{
	char	c;

	if (n < 10)
	{
		c = '0' + n;
		ft_printf_char(c);
		res++;
	}
	else
	{
		res = ft_printf_uns(n / 10, res);
		res = ft_printf_uns(n % 10, res);
	}
	return (res);
}

// This is the function that converts decimal numbers to hex.

// I went off from the ft_putnbr function and recreated it to prints hexidecimal
// numbers. It first checks if the number is 15 or smaller. If so it prints the
// the corresponding char. If not, it recursively calls on the function with
// "num / 16" and "num % 16" so it's remainder get's printed every call.

// It also checks which placeholder it is. If it's %X it'll print the hex in
// uppercase. Else (%x and %p) it'll print it in lowercase.

int	ft_printf_hex(unsigned long num, char x, int res)
{
	char	c;

	if (num < 16)
	{
		if (num < 10)
			c = '0' + num;
		else if (x == 'X')
			c = '7' + num;
		else
			c = 'W' + num;
		ft_printf_char(c);
		res++;
	}
	else
	{
		res = ft_printf_hex(num / 16, x, res);
		res = ft_printf_hex(num % 16, x, res);
	}
	return (res);
}

// This is what i used to check if the conversion to hex went right.

// int	main(void)
// {
// 	int	i;
// 	int	res;

// 	i = 0;
// 	res = 0;
// 	while (i < 65546)
// 	{
// 		ft_printf_hex(i, 'x', res);
// 		printf(" <- hex\n");
// 		printf("%i <- int\n\n", i);
// 		i = i + 321;
// 	}
// 	return (0);
// }
