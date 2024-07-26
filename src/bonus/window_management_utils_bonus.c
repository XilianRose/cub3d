/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_management_utils_bonus.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/21 11:28:59 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/19 15:33:13 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	new_frame(t_game_info *game)
{
	mlx_delete_image(game->mlx, game->image);
	mlx_delete_image(game->mlx, game->fps_image);
	mlx_delete_image(game->mlx, game->player.image);
	game->time = game->mlx->delta_time;
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	raycast(&game->player, &game->map, game->image, game);
	if (!game->image || render_stats(game) == EXIT_FAILURE || \
	mlx_image_to_window(game->mlx, game->image, 0, 0) == -1 || \
	render_player(game) == EXIT_FAILURE)
	{
		mlx_error_wrapper(game->mlx);
		return ;
	}
	mlx_set_instance_depth(game->image->instances, 1);
}

void	process_input(t_game_info *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game);
}
