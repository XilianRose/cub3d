/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/28 11:14:01 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/28 15:35:00 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	render_minimap(t_game_info *game)
{
	t_map_info	map;
	int			y;
	int			x;
	int			yy;
	int			xx;

	y = 0;
	map = game->map;
	map.minimap = mlx_new_image(game->mlx, map.width * TILE_SIZE, map.height * TILE_SIZE);
	while (map.layout[y] != NULL)
	{
		x = 0;
		while (map.layout[y][x] != '\0')
		{
			if (map.layout[y][x] == '1')
			{
				yy = 0;
				while (yy < TILE_SIZE)
				{
					xx = 0;
					while (xx < TILE_SIZE)
					{
						mlx_put_pixel(map.minimap, x + xx, y + yy, 0xFFFFFFFF);
						xx++;
					}
					yy++;
				}
			}
			else if (map.layout[y][x] == '0')
			{
				yy = 0;
				while (yy < TILE_SIZE)
				{
					xx = 0;
					while (xx < TILE_SIZE)
					{
						mlx_put_pixel(map.minimap, x + xx, y + yy, 0xFFFFFF80);
						xx++;
					}
					yy++;
				}
			}
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(game->mlx, map.minimap, \
	10, 10) == -1)
		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
