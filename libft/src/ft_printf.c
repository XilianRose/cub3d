/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:33:29 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:16:14 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>

// This function prints the placeholders (ph).
//
// Using va_arg, arguments are initialized and pointers to the arguments of
// different types are added to the va_list. They are then printed using general
// ft_put~ functions or with the ft_print_hex function in case of %x, %X or %p.

// It prints the "0x" part of the pointer address in this function because the
// functions used to print hexidecimals is recursive.

static int	ft_printf_ph(const char *ph, int i, va_list ap, int res)
{
	char			c;
	char			*str;
	int				nbr;
	unsigned int	u;
	unsigned long	p;

	if (ph[i] == 'c')
		return (c = va_arg(ap, int), (ft_printf_char(c) + res));
	else if (ph[i] == 's')
		return (str = va_arg(ap, char *), (ft_printf_str(str) + res));
	else if (ph[i] == 'p')
	{
		res = ft_printf_str("0x") + res;
		return (p = va_arg(ap, unsigned long), ft_printf_hex(p, ph[i], res));
	}
	else if (ph[i] == 'd' || ph[i] == 'i')
		return (nbr = va_arg(ap, int), (ft_printf_nbr(nbr) + res));
	else if (ph[i] == 'u')
		return (u = va_arg(ap, unsigned int), (ft_printf_uns(u, res)));
	else if (ph[i] == 'x' || ph[i] == 'X')
		return (u = va_arg(ap, unsigned int), ft_printf_hex(u, ph[i], res));
	return (res);
}

// This is the function that prints every printable character.
//
// It iterates through the string and prints every character untill it finds
// an '%', then it checks if it should be printed or if it's a placeholder.
// If it's an placeholder it goes into ft_print_ph function.

static int	ft_printf_cs(const char *c, va_list ap, int res, int i)
{
	int	write_return;

	write_return = 0;
	while (c[i])
	{
		if (c[i] != '%')
		{
			write_return = write(1, c + i, 1);
			i++;
			res = res + write_return;
		}
		else if (c[i] == '%' && c[i + 1] == '%')
		{
			write_return = write(1, "%", 1);
			i = i + 2;
			res = res + write_return;
		}
		else if (c[i] == '%' && c[i + 1] == '\0')
			break ;
		else if (c[i] == '%' && c[i + 1] != '%')
		{
			res = ft_printf_ph(c, i + 1, ap, res);
			i = i + 2;
		}
	}
	return (res);
}

// This is the general printf function. It takes a character string and an
// undefined number of arguments using variable argument list functions.
//
// int res is declared here and given to ft_print_cs with the string and
// va_list. It'll count the printed characters.

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		res;

	res = 0;
	va_start(ap, c);
	res = ft_printf_cs(c, ap, res, 0);
	va_end(ap);
	return (res);
}

// Here i compare the output of the original function (og) to my function (ft)

// int	main(void)
// {
// 	int		res_ft;
	// int		res_og;
	// char	c;
	// void	*ptr;

// c = '5';
// ptr = NULL;
// res_ft = ft_printf("ft: this should print %%\n");
// res_og = printf("og: this should print %%\n");
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// res_ft = ft_printf("ft: this is a string: %s\n", "abc");
// res_og = printf("og: this is a string: %s\n", "abc");
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// res_ft = ft_printf("ft: this is char 1: %c & this is char 2: %c\n", 'c', c);
// res_og = printf("og: this is char 1: %c & this is char 2: %c\n", 'c', c);
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// printf("~~~ HEX testing ~~~\n\n");
// res_ft = ft_printf("ft: this is hex: %x\n", 635635);
// res_og = printf("og: this is hex: %x\n", 635635);
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// res_ft = ft_printf("ft: this is HEX: %X\n", 635635);
// res_og = printf("og: this is HEX: %X\n", 635635);
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// res_ft = ft_printf("ft: this is void ptr: %p\n", &c);
// res_og = printf("og: this is void ptr: %p\n", &c);
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// res_ft = ft_printf("ft: this is decimal: %d\n", 012);
// res_og = printf("og: this is decimal: %d\n", 012);
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// res_ft = ft_printf("ft:this is integer: %i\n", 012);
// res_og = printf("og:this is integer: %i\n", 012);
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// printf("~~~ unsigned decimals testing ~~~\n\n");
// res_ft = ft_printf("ft: this is unsigned decimal: %u\n", 12);
// res_og = printf("og: this is unsigned decimal: %u\n", 12);
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// res_ft = ft_printf("ft: this is unsigned decimal: %u\n", -12);
// res_og = printf("og: this is unsigned decimal: %u\n", -12);
// printf("ft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// printf("~~~ NULL string testing ~~~\n\n");
// res_og = printf(" NULL %s NULL ", NULL);
// printf("\n");
// res_ft = ft_printf(" NULL %s NULL ", NULL);
// printf("\nft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// res_og = printf("%s", (char *) NULL);
// printf("\n");
// res_ft = ft_printf("%s", (char *) NULL);
// printf("\nft returns: %i\nog returns: %i\n\n", res_ft, res_og);
// 	res_ft = ft_printf("%%%");
// 	printf("ft returns: %i\n\n", res_ft);
// 	return (0);
// }
