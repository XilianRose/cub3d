/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:50:32 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/18 14:35:19 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_elements(char *row, t_map_info *map)
{
	if (ft_strnstr(row, "NO ", 3))
		map->no_texture = row;
	else if (ft_strnstr(row, "SO ", 3))
		map->so_texture = row;
	else if (ft_strnstr(row, "WE ", 3))
		map->we_texture = row;
	else if (ft_strnstr(row, "EA ", 3))
		map->ea_texture = row;
	else if (ft_strnstr(row, "C ", 2))
		map->c_color = row;
	else if (ft_strnstr(row, "F ", 2))
		map->f_color = row;
	else
		my_freestr(row);
	return ;
}

bool	elements_not_null(t_map_info *map)
{
	if (map->no_texture == NULL || map->so_texture == NULL || \
	map->we_texture == NULL || map->ea_texture == NULL || \
	map->c_color == NULL || map->f_color == NULL)
		return (false);
	return (true);
}
