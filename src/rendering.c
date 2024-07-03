/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/28 11:14:01 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/03 17:14:03 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_line(int x, int *draw_pixels, unsigned int color, \
mlx_image_t *image)
{
	int	i;

	i = draw_pixels[0];
	while (i != draw_pixels[1])
	{
		mlx_put_pixel(image, x, draw_pixels[0], color);
		i++;
	}
	return ;
}

static void	put_tile(mlx_image_t *image, u_int32_t x, u_int32_t y, u_int32_t color)
{
	int			yy;
	int			xx;

	yy = 0;
	while (yy < TILE_SIZE)
	{
		xx = 0;
		while (xx < TILE_SIZE)
		{
			mlx_put_pixel(image, x * TILE_SIZE + xx, y * TILE_SIZE + yy, color);
			xx++;
		}
		yy++;
	}
	return ;
}

int32_t	render_player(t_game_info *game)
{
	t_player_info	*player;

	player = &game->player;
	player->image = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	put_tile(player->image, 0, 0, 0x80FFFFFF);
	if (mlx_image_to_window(game->mlx, player->image, \
	player->position.x * TILE_SIZE + 10, player->position.y * TILE_SIZE + 10) == -1)
		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int32_t	render_minimap(t_game_info *game)
{
	t_map_info	*map;
	int			y;
	int			x;

	y = 0;
	map = &game->map;
	map->minimap = mlx_new_image(game->mlx, map->width * TILE_SIZE, map->height * TILE_SIZE);
	while (map->layout[y] != NULL)
	{
		x = 0;
		while (map->layout[y][x] != '\0')
		{
			if (map->layout[y][x] == '1')
				put_tile(map->minimap, x, y, 0xFFFFFFCC);
			else if (ft_strchr("0NOSW", map->layout[y][x]) != NULL)
				put_tile(map->minimap, x, y, 0xFFFFFF80);
			x++;
		}
		y++;
	}
	// resize img to std size
	if (mlx_image_to_window(game->mlx, map->minimap, 10, 10) == -1)
		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
