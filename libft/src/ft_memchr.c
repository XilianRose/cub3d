/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:38:53 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:11:05 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		n--;
		s++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s[] = "bonjour";
// 	int c = 'o';
// 	size_t n = 7;

// 	const char *og = memchr(s, c, n);
// 	const char *ft = ft_memchr(s, c, n);

// 	printf("\nog: %p\nft: %p\n\n", og, ft);
// 	return(0);
// }
