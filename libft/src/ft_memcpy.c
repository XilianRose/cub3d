/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:31:09 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:11:13 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret;

	ret = dst;
	if (!dst && !src)
		return (dst);
	while (n > 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		src++;
		n--;
	}
	return (ret);
}

// int	main(void)
// {
// 	char dst1[] = "12345";
// 	char src1[] = "abcde";
// 	char dst2[] = "12345";
// 	char src2[] = "abcde";
// 	size_t n = 0;

// 	memcpy(dst1, src1, n);
// 	ft_memcpy(dst2, src2, n);
// 	printf("\nog: %s\nft: %s\n\n", dst1, dst2);
// 	return (0);
// }
