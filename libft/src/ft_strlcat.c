/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:43:31 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:12:32 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (dstsize < i)
		return (dstsize + j);
	if (dstsize > 0 && i < dstsize)
	{
		ft_strlcpy(dst + i, src, (dstsize - i));
	}
	return (i + j);
}

// int	main(void)
// {
// 	char dst1[11] = "a";
// 	char dst2[11] = "a";
// 	char src[] = "lorem ipsum";
// 	size_t dstsize = 0;
// 	size_t og = strlcat(dst1, src, dstsize);
// 	size_t ft = ft_strlcat(dst2, src, dstsize);

// 	printf("\nog:%zu, %s\nft:%zu, %s\n\n", og, dst1, ft, dst2);
// 	return (0);
// }
