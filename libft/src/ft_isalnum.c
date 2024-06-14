/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 15:15:27 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:08:38 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>
// #include <ctype.h>

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
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
// 	if (isalnum(arg) == ft_isalnum(arg))
// 		printf("output is the same as original function\n");
// 	else
// 		printf("is false\n");
// 	return (0);
// }
