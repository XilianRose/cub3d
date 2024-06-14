/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:49:47 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:12:57 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	ii;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		ii = i;
		j = 0;
		while (hay[ii] && needle[j] && hay[ii] == needle[j] && ii < len)
		{
			j++;
			ii++;
		}
		if (!needle[j])
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char hay[] = "this is the moment";
// 	char needle[] = "mo";
// 	size_t len = 20;

// 	char *og = strnstr(hay, needle, len);
// 	char *ft = ft_strnstr(hay, needle, len);

// 	printf("\nog: %s\nft: %s\n\n", og, ft);
// 	return (0);
// }
