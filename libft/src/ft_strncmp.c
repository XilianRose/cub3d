/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:37:08 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:12:52 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

int	ft_strncmp(const char*s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i) && i < n)
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}

// int	main(void)
// {
// 	char s1[] = "abcdefgh";
// 	char s2[] = "abcdwxyz";
// 	size_t n = 4;

// 	int og = strncmp(s1, s2, n);
// 	int ft = ft_strncmp(s1, s2, n);
// 	printf("\nog: %i\nft: %i\n\n", og, ft);

// 	return (0);
// }
