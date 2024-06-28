/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/28 11:14:01 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/28 19:51:40 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_minimap(mlx_image_t *minimap, u_int32_t x, u_int32_t y, u_int32_t color)
{
	int			yy;
	int			xx;

	yy = 0;
	while (yy < TILE_SIZE)
	{
		xx = 0;
		while (xx < TILE_SIZE)
		{
			mlx_put_pixel(minimap, x * TILE_SIZE + xx, y * TILE_SIZE + yy, color);
			xx++;
		}
		yy++;
	}
	return ;
}

int32_t	render_minimap(t_game_info *game)
{
	t_map_info	map;
	int			y;
	int			x;

	y = 0;
	map = game->map;
	map.minimap = mlx_new_image(game->mlx, map.width * TILE_SIZE, map.height * TILE_SIZE);
	while (map.layout[y] != NULL)
	{
		x = 0;
		while (map.layout[y][x] != '\0')
		{
			if (map.layout[y][x] == '1')
				put_minimap(map.minimap, x, y, 0xFFFFFFCC);
			else if (ft_strchr("0NOSW",map.layout[y][x]) != NULL)
				put_minimap(map.minimap, x, y, 0xFFFFFF80);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(game->mlx, map.minimap, 10, 10) == -1)
		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
