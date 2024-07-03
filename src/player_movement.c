/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:08:57 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/03 14:56:51 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//calculate movement based on time

void	move_up(t_game_info *game)
{
	int	x;
	int	y;

	x = (game->player.image->instances[0].x - 10) / TILE_SIZE;
	y = (game->player.image->instances[0].y - 10) / TILE_SIZE;
	if (game->map.layout[y - 1][x] != '1')
		game->player.image->instances[0].y -= TILE_SIZE;
	return ;
}

void	move_down(t_game_info *game)
{
	int	x;
	int	y;

	x = (game->player.image->instances[0].x - 10) / TILE_SIZE;
	y = (game->player.image->instances[0].y - 10) / TILE_SIZE;
	if (game->map.layout[y + 1][x] != '1')
		game->player.image->instances[0].y += TILE_SIZE;
	return ;
}

void	move_left(t_game_info *game)
{
	int	x;
	int	y;

	x = (game->player.image->instances[0].x - 10) / TILE_SIZE;
	y = (game->player.image->instances[0].y - 10) / TILE_SIZE;
	if (game->map.layout[y][x - 1] != '1')
		game->player.image->instances[0].x -= TILE_SIZE;
	return ;
}

void	move_right(t_game_info *game)
{
	int	x;
	int	y;

	x = (game->player.image->instances[0].x - 10) / TILE_SIZE;
	y = (game->player.image->instances[0].y - 10) / TILE_SIZE;
	if (game->map.layout[y][x + 1] != '1')
		game->player.image->instances[0].x += TILE_SIZE;
	return ;
}
