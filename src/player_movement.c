/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:08:57 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/10 15:09:18 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//calculate movement based on time

void	move_up(t_game_info *game)
{
	t_player_info	*player;
	double			movespeed;
	int				x;
	int				y;

	player = &game->player;
	movespeed = game->time * 3.0;
	x = (int) player->position.x;
	y = (int) player->position.y;
	if (game->map.layout[y][x + (int)(player->dir.x * movespeed)] != '1')
		player->position.x += player->dir.x * movespeed;
	if (game->map.layout[y + (int)(player->dir.y * movespeed)][x] != '1')
		player->position.y += player->dir.y * movespeed;
	return ;
}

void	move_down(t_game_info *game)
{
	t_player_info	*player;
	double			movespeed;
	int				x;
	int				y;

	player = &game->player;
	movespeed = game->time * 3.0;
	x = (int) player->position.x;
	y = (int) player->position.y;
	if (game->map.layout[y][x - (int)(player->dir.x * movespeed)] != '1')
		player->position.x -= player->dir.x * movespeed;
	if (game->map.layout[y - (int)(player->dir.y * movespeed)][x] != '1')
		player->position.y -= player->dir.y * movespeed;
	return ;
}

void	move_left(t_game_info *game)
{
	t_player_info	*player;
	double			movespeed;
	int				x;
	int				y;

	player = &game->player;
	movespeed = game->time * 3.0;
	x = (int) player->position.x;
	y = (int) player->position.y;
	if (game->map.layout[y][x - (int)(player->dir.x * movespeed)] != '1')
		player->position.x -= player->ray.plane.x * movespeed;
	if (game->map.layout[y - (int)(player->dir.y * movespeed)][x] != '1')
		player->position.y -= player->ray.plane.y * movespeed;
	return ;
}

void	move_right(t_game_info *game)
{
	t_player_info	*player;
	double			movespeed;
	int				x;
	int				y;

	player = &game->player;
	movespeed = game->time * 3.0;
	x = (int) player->position.x;
	y = (int) player->position.y;
	if (game->map.layout[y][x + (int)(player->dir.x * movespeed)] != '1')
		player->position.x += player->ray.plane.x * movespeed;
	if (game->map.layout[y + (int)(player->dir.y * movespeed)][x] != '1')
		player->position.y += player->ray.plane.y * movespeed;
	return ;
}
