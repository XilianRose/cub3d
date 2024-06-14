/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_allocarray.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 13:05:59 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/09 11:27:21 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*	this function allocates memory for an array of character pointers */
char	**my_allocarray(int x, int y)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_calloc(y + 1, sizeof(char *));
	if (!temp)
		return (perror("Error\n"), NULL);
	while (i < y)
	{
		temp[i] = ft_calloc(x + 1, sizeof(char));
		if (!temp[i])
		{
			my_freearray(temp);
			return (perror("Error\n"), NULL);
		}
		i++;
	}
	return (temp);
}
