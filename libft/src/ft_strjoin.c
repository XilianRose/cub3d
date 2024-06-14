/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 13:15:20 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:12:27 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;
	size_t	count;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	count = len_s1 + len_s2 + 1;
	res = ft_calloc(count, sizeof(char));
	if (res)
	{
		ft_memcpy(res, s1, len_s1);
		ft_memcpy(res + len_s1, s2, len_s2);
		return (res);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s1[] = "lorem ipsum";
// 	char s2[] = "dolor sit amet";

// 	char *og = ft_strjoin(s1, s2);
// 	printf("\nog: %s\n\n", og);
// 	return (0);
// }
