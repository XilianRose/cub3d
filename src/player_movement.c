/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:08:57 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/30 23:02:08 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_game_info *game)
{
	int	x;
	int	y;

	x = game->player.image->instances[0].x / TILE_SIZE;
	y = game->player.image->instances[0].y / TILE_SIZE;
	if (ft_strchr("0NESW", game->map.layout[y - 1][x]) != NULL)
		game->player.image->instances[0].y -= TILE_SIZE;
	return ;
}

void	move_down(t_game_info *game)
{
	int	x;
	int	y;

	x = game->player.image->instances[0].x / TILE_SIZE;
	y = game->player.image->instances[0].y / TILE_SIZE;
	if (ft_strchr("0NESW", game->map.layout[y + 1][x]) != NULL)
		game->player.image->instances[0].y += TILE_SIZE;
	return ;
}

void	move_left(t_game_info *game)
{
	int	x;
	int	y;

	x = game->player.image->instances[0].x / TILE_SIZE;
	y = game->player.image->instances[0].y / TILE_SIZE;
	if (ft_strchr("0CEP", game->map.layout[y][x - 1]) != NULL)
		game->player.image->instances[0].x -= TILE_SIZE;
	return ;
}

void	move_right(t_game_info *game)
{
	int	x;
	int	y;

	x = game->player.image->instances[0].x / TILE_SIZE;
	y = game->player.image->instances[0].y / TILE_SIZE;
	if (ft_strchr("0CEP", game->map.layout[y][x + 1]) != NULL)
		game->player.image->instances[0].x += TILE_SIZE;
	return ;
}
