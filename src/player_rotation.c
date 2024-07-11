/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_rotation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 14:18:17 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/11 17:08:01 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	rotate_left(t_game_info *game)
{
	t_player_info	*player;
	double			rotatespeed;
	double			old_dir_y;
	double			old_plane_y;

	player = &game->player;
	rotatespeed = 0.035;
	old_dir_y = player->dir.y;
	old_plane_y = player->ray.plane.y;
	player->dir.y = player->dir.y * cos(rotatespeed) - \
	player->dir.x * sin(rotatespeed);
	player->dir.x = old_dir_y * sin(rotatespeed) + \
	player->dir.x * cos(rotatespeed);
	player->ray.plane.y = player->ray.plane.y * cos(rotatespeed) - \
	player->ray.plane.x * sin(rotatespeed);
	player->ray.plane.x = old_plane_y * sin(rotatespeed) + \
	player->ray.plane.x * cos(rotatespeed);
}

void	rotate_right(t_game_info *game)
{
	t_player_info	*player;
	double			rotatespeed;
	double			old_dir_y;
	double			old_plane_y;

	player = &game->player;
	rotatespeed = 0.035;
	old_dir_y = player->dir.y;
	old_plane_y = player->ray.plane.y;
	player->dir.y = player->dir.y * cos(-rotatespeed) - \
	player->dir.x * sin(-rotatespeed);
	player->dir.x = old_dir_y * sin(-rotatespeed) + \
	player->dir.x * cos(-rotatespeed);
	player->ray.plane.y = player->ray.plane.y * cos(-rotatespeed) - \
	player->ray.plane.x * sin(-rotatespeed);
	player->ray.plane.x = old_plane_y * sin(-rotatespeed) + \
	player->ray.plane.x * cos(-rotatespeed);
}
