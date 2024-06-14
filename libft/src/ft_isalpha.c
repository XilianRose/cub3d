/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 11:49:02 by mstegema      #+#    #+#                 */
/*   Updated: 2022/10/06 12:09:20 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
// 	if (isalpha(arg) == ft_isalpha(arg))
// 		printf("output is the same as original function\n");
// 	else
// 		printf("is false\n");
// 	return (0);
// }
