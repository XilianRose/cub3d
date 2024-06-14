/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 13:03:08 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:13:13 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	substr_len;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s[0] == '\0' || start > s_len)
		substr_len = 0;
	else
		substr_len = ft_strlen(s + start);
	if (substr_len > len)
		substr_len = len;
	res = ft_calloc(substr_len + 1, sizeof(char));
	if (res)
	{
		if (start < s_len)
			ft_memmove(res, s + start, substr_len);
		return (res);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s[] = "lorem ipsum dolor sit amet";
// 	int start = 9;
// 	size_t len = 5;

// 	char *og = ft_substr(s, start, len);
// 	printf("\nog: %s\n\n", og);
// 	return (0);
// }

// vvische's main
// int main(void)
// {
// 	char *source = "abcd";
// 	char *extra = "mag niet";
// 	char *new = ft_substr(source, 3, 20);
// 	int j = strlen(new);

// 	int i = 0;
// 	while (i < 50)
// 	{
// 		printf("[%c]\n", new[i]);
// 		i++;
// 	}
// 	printf("string: %s\nsize: %i\n\n", new, j);
// 	return 0;
// }
