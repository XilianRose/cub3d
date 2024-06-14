/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 13:12:05 by mstegema      #+#    #+#                 */
/*   Updated: 2022/10/06 18:14:56 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_isascii(int c)
{
	int	res;

	res = 0;
	if (c >= 0 && c <= 127)
		res = 1;
	return (res);
}

// int	main(int argc, char **argv)
// {
// 	long	arg;

// 	if (argc != 2)
// 	{
// 		printf("ERROR: too many or no arguments given\n");
// 		return (0);
// 	}
// 	arg = strtol(argv[1], NULL, 10);
// 	if (isascii(arg) == ft_isascii(arg))
// 		printf("output is the same as original function\n");
// 	else
// 		printf("is false\n");
// 	return (0);
// }
