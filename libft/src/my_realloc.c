/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 13:59:03 by mstegema      #+#    #+#                 */
/*   Updated: 2023/04/06 14:30:50 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

/*	This function imitates the realloc function from the stdlib.h library. It's a
	bit of a simplified version, as i don't know the actual size of the block of
	memory that needs to be altered. Therefore this functions always bases the
	size of the memory block on the initialized bits of memory.

	Because of this it will always allocate a new block of memory, when resizing,
	and copies up to the lesser of the new and old sizes of content to it. It will
	then return a pointer to the new allocated block of memory when succesfull and
	NULL if unsuccesfull. If allocation fails, *ptr will not be freed.

	If ptr is NULL, then the call is equivalent to ft_calloc(size), for all values
	of size; if size is equal to zero, and ptr is not NULL, then the call is
	equivalent to free(ptr). Different from the original realloc, my_realloc will
	initialize the newly allocated memory to zero */

void	*my_realloc(void *ptr, size_t size)
{
	void	*res;
	size_t	len;

	res = NULL;
	len = ft_strlen(ptr);
	if (ptr == NULL)
		return (ft_calloc(0, size));
	else if (size == 0)
		return (my_freestr(ptr), NULL);
	res = ft_calloc(0, size);
	if (!res)
		return (NULL);
	if (size > len)
		ft_memmove(res, ptr, len);
	else
		ft_memmove(res, ptr, size);
	printf("oud2: %p\n", &ptr);
	return (my_freestr(ptr), res);
}

// int	main(void)
// {
// 	char	*str_old;
// 	char	*str_new;

// 	str_old = malloc(15 * sizeof(char));
// 	if (!str_old)
// 		return (printf("initial malloc failed"), 1);
// 	ft_memmove(str_old, "potatoes", 8);
// 	printf("oud1: %p\n", &str_old);
// 	str_new = my_realloc(str_old, 5);
// 	printf("str_new = %s\n", str_new);
// 	printf("new: %p\n", &str_new);
// 	// str_old = my_realloc(str_new, )
// 	return (0);
// }
