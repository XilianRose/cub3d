/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 13:39:55 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/18 16:03:16 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_struct(t_map_info *map)
{
	my_freestr(map->no_texture);
	my_freestr(map->so_texture);
	my_freestr(map->we_texture);
	my_freestr(map->ea_texture);
	my_freestr(map->f_color);
	my_freestr(map->c_color);
	return ;
}
