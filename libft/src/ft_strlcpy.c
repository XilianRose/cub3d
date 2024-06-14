/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:38:00 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:12:37 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = ft_strlen(src);
	return (i);
}

// int	main(void)
// {
// 	char src1[] = "123456";
// 	char src2[] = "123456";
// 	char dst1[15];
// 	char dst2[15];
// 	size_t dstsize = 2;
// 	size_t og = strlcpy(dst1, src1, dstsize);
// 	size_t ft = ft_strlcpy(dst2, src2, dstsize);

// 	printf("\nog:%zu, %s\nft:%zu, %s\n\n", og, dst1, ft, dst2);
// 	return (0);
// }
