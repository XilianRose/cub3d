/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 13:39:55 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/19 13:48:05 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_mlx_texture(mlx_texture_t *texture)
{
	if (texture != NULL)
		mlx_delete_texture(texture);
}

void	free_map_struct(t_map_info *map)
{
	free_mlx_texture(map->no_texture);
	free_mlx_texture(map->so_texture);
	free_mlx_texture(map->we_texture);
	free_mlx_texture(map->ea_texture);
	my_freearray(map->layout);
	return ;
}

char	**realloc_arr(char **ptr, size_t size)
{
	char	**res;
	size_t	old_size;

	res = NULL;
	old_size = 0;
	if (ptr == NULL)
		return ((char **)ft_calloc(1, sizeof(char *) * (size)));
	else if (size == 0)
		return (my_freearray(ptr), NULL);
	res = (char **)ft_calloc(1, sizeof(char *) * (size));
	if (!res)
		return (NULL);
	while (ptr[old_size] != NULL)
		old_size++;
	old_size += 1;
	if (size > old_size)
		ft_memmove(res, ptr, sizeof(char *) * (old_size));
	else
	{
		ft_memmove(res, ptr, sizeof(char *) * (size));
		res[size - 1] = 0;
	}
	return (free(ptr), res);
}
