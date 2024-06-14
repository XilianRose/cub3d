/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:11:45 by mstegema      #+#    #+#                 */
/*   Updated: 2022/10/05 15:13:56 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}

// int	main(void)
// {
// 	int c = 123;
// 	int og = toupper(c);
// 	int ft = ft_toupper(c);
// 	printf("\nog: %i\nft: %i\n\n", og, ft);
// 	return (0);
// }
