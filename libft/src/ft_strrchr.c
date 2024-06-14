/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:06:34 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:13:02 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == (char) c)
		return ((char *)(s + i));
	return (NULL);
}

// int	main(void)
// {
// 	char str[] = "abxcdeabxcde";
// 	int	c = 'x';
// 	char *og = strrchr(str, c);
// 	char *ft = ft_strrchr(str, c);

// 	printf("\nog: %p\nft: %p\n\n", og, ft);
// 	return (0);
// }
