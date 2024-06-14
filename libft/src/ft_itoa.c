/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 17:47:41 by mstegema      #+#    #+#                 */
/*   Updated: 2023/06/09 15:31:50 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>

static char	*ft_intloop(int n, char *res, size_t len)
{
	while (n)
	{
		res[len - 1] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = my_intlen(n);
	res = ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	if (n == -2147483648)
	{
		ft_memmove(res, "-2147483648", len);
		return (res);
	}
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	ft_intloop(n, res, len);
	return (res);
}

// int	main(void)
// {
// 	int i = ft_strlen(ft_itoa(INT32_MIN));
// 	int j = ft_strlen(ft_itoa(INT32_MAX));

// 	printf("\nint min string is %i long\nint max string is %i long \n\n", i, j);
// 	return(0);
// }
