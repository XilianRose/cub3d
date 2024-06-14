/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:04:20 by mstegema      #+#    #+#                 */
/*   Updated: 2023/03/03 15:10:52 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
// #include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst -> content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst -> next;
	}
	return (new_lst);
}

// void	*v_strlen(void *s)
// {
// 	int	*res;

// 	res = malloc(sizeof(int));
// 	if (res)
// 		*res = ft_strlen(s);
// 	return ((void *)(res));
// }

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew("hello!");
// 	ft_lstmap(lst, &v_strlen, &free);
// 	return (0);
// }
