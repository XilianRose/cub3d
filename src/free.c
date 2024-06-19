/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 13:39:55 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/19 14:37:49 by mstegema      ########   odam.nl         */
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

void	free_3(char *str1, char *str2, char *str3)
{
	my_freestr(str1);
	my_freestr(str2);
	my_freestr(str3);
	return ;
}
