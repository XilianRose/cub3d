/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_management_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/21 11:28:59 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/19 15:32:37 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	loophook(void *param)
{
	t_game_info	*game;

	game = param;
	process_input(game);
	new_frame(game);
}

static void	cursorhook(double xpos, double ypos, void *param)
{
	t_game_info	*game;

	game = param;
	if (mlx_is_mouse_down(game->mlx, 0) && xpos > game->cursor.x)
		rotate_right(game);
	if (mlx_is_mouse_down(game->mlx, 0) && xpos < game->cursor.x)
		rotate_left(game);
	game->cursor.x = xpos;
	game->cursor.y = ypos;
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

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!mlx)
		return (mlx_error_wrapper(NULL));
	game->mlx = mlx;
	if (render_minimap(game) == EXIT_FAILURE)
		return (mlx_terminate(game->mlx), EXIT_FAILURE);
	mlx_loop_hook(mlx, &loophook, game);
	mlx_key_hook(mlx, &keyhook, game);
	mlx_cursor_hook(mlx, &cursorhook, game);
	mlx_loop(game->mlx);
	mlx_close_window(game->mlx);
	return (mlx_terminate(game->mlx), EXIT_SUCCESS);
}
