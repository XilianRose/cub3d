/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 15:42:07 by mstegema      #+#    #+#                 */
/*   Updated: 2023/04/06 13:59:45 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	my_intlen(int n)
{
	size_t	i;

	i = 0;
	if ((n == 0) || (n < 0))
		i = 1;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
