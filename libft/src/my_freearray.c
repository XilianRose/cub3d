/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_freearray.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 13:10:04 by mstegema      #+#    #+#                 */
/*   Updated: 2023/07/06 16:07:18 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*	this function first free's the allocated rows, then the map itself and then
	set's them to NULL. This is done after checking it can be freed */
void	my_freearray(char **array)
{
	int	i;

	i = 0;
	while (array != NULL && array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	if (array != NULL)
	{
		free(array);
		array = NULL;
	}
}
