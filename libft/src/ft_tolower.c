/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:14:58 by mstegema      #+#    #+#                 */
/*   Updated: 2022/10/05 15:15:40 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}

// int	main(void)
// {
// 	int c = 90;
// 	int og = tolower(c);
// 	int ft = ft_tolower(c);
// 	printf("\nog: %i\nft: %i\n\n", og, ft);
// 	return(0);
// }
