/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:35:37 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:11:17 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			*(unsigned char *)(dst + len - 1) = *(unsigned char *)
				(src + len - 1);
			len--;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char dst1[] = "12345";
// 	char src1[] = "abcde";
// 	char dst2[] = "12345";
// 	char src2[] = "abcde";
// 	size_t len = 3;

// 	memmove(dst1, src1, len);
// 	ft_memmove(dst2, src2, len);
// 	printf("\nog: %s\nft: %s\n\n", dst1, dst2);
// 	return (0);
// }
