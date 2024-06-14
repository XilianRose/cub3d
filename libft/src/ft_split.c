/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 17:42:19 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:11:59 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>

static int	ft_nmbofstrings(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((s[0] != (char)c) && (s[0] != '\0'))
		j++;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			if ((s[i + 1] != (char)c) && (s[i + 1] != '\0'))
				j++;
		}
		i++;
	}
	return (j);
}

static int	ft_substrlen(const char *s, unsigned int start, char c)
{
	size_t	i;

	i = 0;
	while (s[start] && s[start] != (char)c)
	{
		i++;
		start++;
	}
	return (i);
}

static void	*ft_freeall(char **array, int i)
{
	while (array[i])
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (NULL);
}

static size_t	ft_begin(char const *s, char c, size_t start)
{
	while (s[start] == (char)c)
		start++;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;
	size_t	i;
	size_t	start;
	size_t	len;

	count = ft_nmbofstrings(s, c);
	res = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	start = 0;
	len = 0;
	while (i < count)
	{
		start = start + len;
		start = ft_begin(s, c, start);
		len = ft_substrlen(s, start, c);
		res[i] = ft_substr(s, start, len);
		if (!(res[i]))
			return (ft_freeall(res, i));
		i++;
	}
	return (res);
}

// int	main(void)
// {
// 	// char	str[] = "stress is de leven";
// 	// char	c = ' ';
// 	char	**array = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');

// 	while (*array != NULL)
// 	{
// 		printf("string = %s\n", *array);
// 		array++;
// 	}
// 	return (0);
// }
