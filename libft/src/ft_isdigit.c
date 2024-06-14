/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 15:06:33 by mstegema      #+#    #+#                 */
/*   Updated: 2022/10/06 12:09:19 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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
// 	if (isdigit(arg) == ft_isdigit(arg))
// 		printf("output is the same as original function\n");
// 	else
// 		printf("is false\n");
// 	return (0);
// }
