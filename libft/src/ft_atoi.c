/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:56:05 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:09:53 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	size_t	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		neg = -1;
		i++;
	}
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (res * neg);
		i++;
	}
	return (res * neg);
}

// int	main(void)
// {
// 	char str[] = "++47";
// 	int og = atoi(str);
// 	int ft = ft_atoi(str);

// 	printf("\nog: %i\nft: %i\n\n", og, ft);
// 	return (0);
// }
