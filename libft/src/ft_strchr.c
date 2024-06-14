/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:22:32 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:12:11 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

// int	main(void)
// {
// 	char str[] = "abcdexabcde";
// 	int	i = 'x';
// 	char *og = strchr(str, i);
// 	char *ft = ft_strchr(str, i);

// 	printf("\nog: %p\nft: %p\n\n", og, ft);
// 	return (0);
// }
