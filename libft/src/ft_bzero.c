/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:26:50 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:09:26 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <strings.h>
// #include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

// int	main(void)
// {
// 	char str1[] = "abcde";
// 	char str2[] = "abcde";
// 	size_t n = 0;

// 	bzero(str1, n);
// 	ft_bzero(str2, n);
// 	printf("\nog: %s\nft: %s\n\n", str1, str2);
// 	return (0);
// }
