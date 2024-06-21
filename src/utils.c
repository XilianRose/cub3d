/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:32:23 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/21 13:09:36 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_map_info(t_game_info *game)
{
	game->map.width = 0;
	game->map.height = 0;
	game->map.no_texture = NULL;
	game->map.so_texture = NULL;
	game->map.we_texture = NULL;
	game->map.ea_texture = NULL;
	game->map.f_color = NULL;
	game->map.c_color = NULL;
	game->player.orientation = 0;
	game->player.position.x = 0;
	game->player.position.y = 0;
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
