/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:20:48 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:11:21 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	void	*ret;

	ret = b;
	while (len > 0)
	{
		*(unsigned char *)b = (unsigned char)c;
		len--;
		b++;
	}
	return (ret);
}

// int	main(void)
// {
// 	char str1[6] = "00000";
// 	char str2[6] = "00000";
// 	int c1 = 125;
// 	int c2 = 126;
// 	size_t len = 6;

// 	memset(str1, c1, len);
// 	ft_memset(str2, c2, len);
// 	// str2[5] = 0;
// 	printf("\nog: %s\nft: %s\n\n", str1, str2);
// 	return (0);
// }
