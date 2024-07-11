/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_rotation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 14:18:17 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/11 15:14:11 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	rotate_right(t_game_info *game)
{
	t_player_info	*player;
	double			rotatespeed;
	double			old_dir_x;
	double			old_plane_x;

	player = &game->player;
	rotatespeed = 0.03;
	printf("rotatespeed is: %f\n", rotatespeed);
	old_dir_x = player->dir.x;
	old_plane_x = player->ray.plane.x;
	player->dir.x = player->dir.x * cos(rotatespeed) - player->dir.y * sin(rotatespeed);
	player->dir.y = old_dir_x * sin(rotatespeed) + player->dir.y * cos(rotatespeed);
	player->ray.plane.x = player->ray.plane.x * sin(rotatespeed) - player->ray.plane.y * sin(rotatespeed);
	player->ray.plane.y = old_plane_x * sin(rotatespeed) + player->ray.plane.y * cos(rotatespeed);
}

void	rotate_left(t_game_info *game)
{
	t_player_info	*player;
	double			rotatespeed;
	double			old_dir_x;
	double			old_plane_x;

	player = &game->player;
	rotatespeed = 0.03; 
	old_dir_x = player->dir.x;
	old_plane_x = player->ray.plane.x;
	player->dir.x = player->dir.x * cos(-rotatespeed) - player->dir.y * sin(-rotatespeed);
	player->dir.y = old_dir_x * sin(-rotatespeed) + player->dir.y * cos(-rotatespeed);
	player->ray.plane.x = player->ray.plane.x * sin(-rotatespeed) - player->ray.plane.y * sin(-rotatespeed);
	player->ray.plane.y = old_plane_x * sin(-rotatespeed) + player->ray.plane.y * cos(-rotatespeed);
}
