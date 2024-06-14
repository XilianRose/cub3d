/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:00:24 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:12:42 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <string.h>
// #include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char str[25] = " 789 h";
// 	int org = strlen(str);
// 	int mine = ft_strlen(str);
// 	printf("\nog: %i\nft: %i\n\n", org, mine);
// 	return (0);
// }
