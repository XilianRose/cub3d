/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:34:57 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:13:28 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*res;
// 	size_t	len;
// 	size_t	i;

// 	len = count * size;
// 	res = malloc(len);
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	while (len > 0)
// 	{
// 		*(unsigned char *)(res + i) = (unsigned char)0;
// 		len--;
// 		i++;
// 	}
// 	return (res);
// }

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	void	*ret;

// 	ret = dst;
// 	while (n > 0)
// 	{
// 		*(unsigned char *)dst = *(unsigned char *)src;
// 		dst++;
// 		src++;
// 		n--;
// 	}
// 	return (ret);
// }

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;
	size_t	count;

	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
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

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
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
