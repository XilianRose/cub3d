/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 17:38:08 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:13:08 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>

static size_t	ft_strstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static size_t	ft_strend(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(s1) == 0)
		i = 0;
	else
		i = (ft_strlen(s1) - 1);
	j = 0;
	while ((i > 0) && set[j])
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	int		size;
	size_t	i;

	start = ft_strstart(s1, set);
	end = ft_strend(s1, set);
	if (s1[0] == '\0')
		size = 1;
	else
		size = (end - start + 2);
	if (size < 0)
		size = 1;
	res = ft_calloc(size, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	return (res);
}

// int	main(void)
// {
// 	char s[] = "";
// 	char set[] = "";
// 	char *res = ft_strtrim(s, set);

// 	printf("\nold string: %s\nnew string: %s\n\n", s, res);
// 	int i = 0;
// 	while (set[i] != '\0')
// 	{
// 		printf("char removed: [%c]\n", set[i]);
// 		i++;
// 	}
// 	return (0);
// }
