/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:32:23 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/21 11:58:39 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_map_info(t_map_info *map)
{
	map->width = 0;
	map->height = 0;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->f_color = NULL;
	map->c_color = NULL;
	map->player.orientation = 0;
	map->player.position.x = 0;
	map->player.position.y = 0;
}

void	error_message(t_error *errme)
{
	errme->file0 = "Error\nplease give one filename as argument\n";
	errme->file1 = "Error\nnot a '.cub' map description file\n";
	errme->file2 = "Error\nencountered problem while opening the file\n";
	errme->map0 = "Error\nscene description is missing 1 or more elements\n";
	errme->map1 = "Error\nmap is not properly closed\n";
	errme->map2 = "Error\nmap contains invalid characters\n";
	errme->map3 = "Error\nmap contains more than 1 player starting positions\n";
	errme->map4 = "Error\nmap contains no player starting positions\n";
	return ;
}

void	exit_wrapper(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
