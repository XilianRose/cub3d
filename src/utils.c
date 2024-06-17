/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:32:23 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/17 18:12:17 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_map_info(t_map_info *map)
{
	map->rows = 0;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->f_color = NULL;
	map->c_color = NULL;
}

void	error_message(t_error *errme)
{
	errme->file0 = "Error\nplease give one filename as argument\n";
	errme->file1 = "Error\nnot a '.cub' map description file\n";
	errme->file2 = "Error\nencountered problem while opening the file\n";
	return ;
}
