/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:40:21 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:11:09 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char s1[] = "0";
// 	char s2[] = "0";
// 	size_t n = 1;
// 	int og = memcmp(s1, s2, n);
// 	int ft = ft_memcmp(s1, s2, n);

// 	printf("\nog: %i\nft: %i\n\n", og, ft);
// 	return(0);
// }
