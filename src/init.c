/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 17:37:40 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/17 15:31:22 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_ray_info_2(t_game_info *game)
{
	if (game->player.orientation == 'E')
	{
		game->player.ray.plane.x = 0;
		game->player.ray.plane.y = 1;
		game->player.dir.x = 1;
		game->player.dir.y = 0;
	}
	if (game->player.orientation == 'W')
	{
		game->player.ray.plane.x = 0;
		game->player.ray.plane.y = -1;
		game->player.dir.x = -1;
		game->player.dir.y = 0;
	}
	return ;
}

void	initialize_ray_info(t_game_info *game)
{
	if (game->player.orientation == 'N')
	{
		game->player.ray.plane.x = 1;
		game->player.ray.plane.y = 0;
		game->player.dir.x = 0;
		game->player.dir.y = -1;
	}
	if (game->player.orientation == 'S')
	{
		game->player.ray.plane.x = -1;
		game->player.ray.plane.y = 0;
		game->player.dir.x = 0;
		game->player.dir.y = 1;
	}
	initialize_ray_info_2(game);
	return ;
}

void	initialize_map_info(t_game_info *game)
{
	game->map.width = 0;
	game->map.height = 0;
	game->map.layout = NULL;
	game->map.no_texture = NULL;
	game->map.so_texture = NULL;
	game->map.we_texture = NULL;
	game->map.ea_texture = NULL;
	game->map.f_color = 0;
	game->map.c_color = 0;
	game->player.orientation = 0;
	game->player.position.x = 0;
	game->player.position.y = 0;
	game->time = 0;
	game->image = NULL;
	game->fps_image = NULL;
	game->player.image = NULL;
	return ;
}
