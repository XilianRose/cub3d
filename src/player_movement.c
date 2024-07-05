/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:08:57 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/05 15:15:43 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//calculate movement based on time

#define MOVESPEED 0.6

void	move_up(t_game_info *game)
{
	t_player_info	*player;
	int				x;
	int				y;

	player = &game->player;
	x = (int) player->position.x;
	y = (int) player->position.y;
	if (game->map.layout[y][x + (int)(player->dir.x * MOVESPEED)] != '1')
		player->position.x += (int)(player->dir.x * MOVESPEED);
	if (game->map.layout[y + (int)(player->dir.y * MOVESPEED)][x] != '1')
		player->position.y += (int)(player->dir.y * MOVESPEED);
	return ;
}

void	move_down(t_game_info *game)
{
	t_player_info	*player;
	int				x;
	int				y;

	player = &game->player;
	x = (int) player->position.x;
	y = (int) player->position.y;
	if (game->map.layout[y][x - (int)(player->dir.x * MOVESPEED)] != '1')
		player->position.x -= (int)(player->dir.x * MOVESPEED);
	if (game->map.layout[y - (int)(player->dir.y * MOVESPEED)][x] != '1')
		player->position.y -= (int)(player->dir.y * MOVESPEED);
	return ;
}

void	move_left(t_game_info *game)
{
	int	x;
	int	y;

	x = (game->player.image->instances[0].x - 10) / game->map.ratio;
	y = (game->player.image->instances[0].y - 10) / game->map.ratio;
	if (game->map.layout[y][x - 1] != '1')
		game->player.image->instances[0].x -= game->map.ratio;
	return ;
}

void	move_right(t_game_info *game)
{
	int	x;
	int	y;

	x = (game->player.image->instances[0].x - 10) / game->map.ratio;
	y = (game->player.image->instances[0].y - 10) / game->map.ratio;
	if (game->map.layout[y][x + 1] != '1')
		game->player.image->instances[0].x += game->map.ratio;
	return ;
}
