/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/21 11:28:59 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/21 15:15:17 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	error(mlx_t	*mlx)
{
	if (mlx)
		mlx_close_window(mlx);
	ft_putstr_fd((char *) mlx_strerror(mlx_errno), 2);
	mlx_terminate(mlx);
	return (EXIT_FAILURE);
}

static void	loophook(void *param)
{
	t_game_info	*game;

	game = param;
	mlx_delete_image(game->mlx, game->image);
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->image || \
		mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
	{
		error(game->mlx);
		return ;
	}
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
	if (((keydata.key == MLX_KEY_UP) || (keydata.key == MLX_KEY_W))
		&& (keydata.action == MLX_RELEASE))
		return ;
	if (((keydata.key == MLX_KEY_DOWN) || (keydata.key == MLX_KEY_S))
		&& (keydata.action == MLX_RELEASE))
		return ;
	if (((keydata.key == MLX_KEY_LEFT) || (keydata.key == MLX_KEY_A))
		&& (keydata.action == MLX_RELEASE))
		return ;
	if (((keydata.key == MLX_KEY_RIGHT) || (keydata.key == MLX_KEY_D))
		&& (keydata.action == MLX_RELEASE))
		return ;
}

int32_t	window_management(t_game_info *game)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!mlx)
		return (error(NULL));
	game->mlx = mlx;
	mlx_loop_hook(mlx, &loophook, game);
	mlx_key_hook(mlx, &keyhook, game);
	mlx_loop(game->mlx);
	mlx_close_window(game->mlx);
	return (mlx_terminate(game->mlx), EXIT_SUCCESS);
}
