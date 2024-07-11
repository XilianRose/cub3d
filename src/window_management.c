/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/21 11:28:59 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/11 15:45:02 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	new_frame(t_game_info *game)
{
	mlx_delete_image(game->mlx, game->image);
	mlx_delete_image(game->mlx, game->player.image);
	mlx_delete_image(game->mlx, game->fps_image);
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

static void	process_input(t_game_info *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || \
	(mlx_is_key_down(game->mlx, MLX_KEY_W)))
		move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || \
	(mlx_is_key_down(game->mlx, MLX_KEY_S)))
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

static void	loophook(void *param)
{
	t_game_info	*game;

	game = param;
	process_input(game);
	new_frame(game);
}

static void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game_info	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_RELEASE)
		mlx_set_window_size(game->mlx, game->mlx->width + 32,
			game->mlx->height + 32);
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_RELEASE)
		mlx_set_window_size(game->mlx, game->mlx->width - 32,
			game->mlx->height - 32);
}

int32_t	window_management(t_game_info *game)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!mlx)
		return (mlx_error_wrapper(NULL));
	game->mlx = mlx;
	if (render_minimap(game) == EXIT_FAILURE)
		return (mlx_terminate(game->mlx), EXIT_FAILURE);
	mlx_loop_hook(mlx, &loophook, game);
	mlx_key_hook(mlx, &keyhook, game);
	mlx_loop(game->mlx);
	mlx_close_window(game->mlx);
	return (mlx_terminate(game->mlx), EXIT_SUCCESS);
}
