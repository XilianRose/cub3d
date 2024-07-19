/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:08:57 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/18 14:16:13 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	move_up(t_game_info *game)
{
	t_player_info	*player;
	double			movespeed;
	double			x;
	double			y;

	player = &game->player;
	movespeed = game->time * 3.0;
	x = player->position.x;
	y = player->position.y;
	if (game->map.layout[(int)y][(int)(x + player->dir.x * movespeed)] != '1')
		player->position.x += player->dir.x * movespeed;
	if (game->map.layout[(int)(y + player->dir.y * movespeed)][(int)x] != '1')
		player->position.y += player->dir.y * movespeed;
	return ;
}

void	move_down(t_game_info *game)
{
	t_player_info	*player;
	double			movespeed;
	double			x;
	double			y;

	player = &game->player;
	movespeed = game->time * 3.0;
	x = player->position.x;
	y = player->position.y;
	if (game->map.layout[(int)y][(int)(x - player->dir.x * movespeed)] != '1')
		player->position.x -= player->dir.x * movespeed;
	if (game->map.layout[(int)(y - player->dir.y * movespeed)][(int)x] != '1')
		player->position.y -= player->dir.y * movespeed;
	return ;
}

void	move_left(t_game_info *game)
{
	t_player_info	*player;
	double			movespeed;
	double			x;
	double			y;

	player = &game->player;
	movespeed = game->time * 3.0;
	x = player->position.x;
	y = player->position.y;
	if (game->map.layout[(int)y][(int)(x - player->ray.plane.x * movespeed)] \
		!= '1')
		player->position.x -= player->ray.plane.x * movespeed;
	if (game->map.layout[(int)(y - player->ray.plane.y * movespeed)][(int)x] \
		!= '1')
		player->position.y -= player->ray.plane.y * movespeed;
	return ;
}

void	move_right(t_game_info *game)
{
	t_player_info	*player;
	double			movespeed;
	double			x;
	double			y;

	player = &game->player;
	movespeed = game->time * 3.0;
	x = player->position.x;
	y = player->position.y;
	if (game->map.layout[(int)y][(int)(x + player->ray.plane.x * movespeed)] \
		!= '1')
		player->position.x += player->ray.plane.x * movespeed;
	if (game->map.layout[(int)(y + player->ray.plane.y * movespeed)][(int)x] \
		!= '1')
		player->position.y += player->ray.plane.y * movespeed;
	return ;
}
