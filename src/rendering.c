/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/28 11:14:01 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/05 14:40:54 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_line(int x, t_ray *ray, unsigned int color, \
mlx_image_t *image)
{
	unsigned int	i;

	i = ray->line_start;
	while (i != ray->line_end)
	{
		mlx_put_pixel(image, x, i, color);
		i++;
	}
	return ;
}

static void	put_tile(mlx_image_t *image, t_coordinates *coord, \
unsigned int color, int ratio)
{
	int			yy;
	int			xx;

	yy = 0;
	while (yy < ratio)
	{
		xx = 0;
		while (xx < ratio)
		{
			mlx_put_pixel(image, coord->x * ratio + xx, \
			coord->y * ratio + yy, color);
			xx++;
		}
		yy++;
	}
	return ;
}

int32_t	render_player(t_game_info *game)
{
	t_player_info	*player;
	t_map_info		map;
	t_coordinates	coord;

	coord.y = 0;
	coord.x = 0;
	player = &game->player;
	map = game->map;
	player->image = mlx_put_string(game->mlx, "v", \
	player->position.x * map.ratio + 10 + map.ratio / 4, \
	player->position.y * map.ratio + 10 + map.ratio / 4);
	if (!player->image)
		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
	mlx_set_instance_depth(player->image->instances, 11);
	return (EXIT_SUCCESS);
}

// int32_t	render_player(t_game_info *game)
// {
// 	t_player_info	*player;
// 	t_map_info		map;
// 	t_coordinates	coord;

// 	coord.y = 0;
// 	coord.x = 0;
// 	player = &game->player;
// 	map = game->map;
// 	player->image = mlx_new_image(game->mlx, map.ratio / 2, map.ratio / 2);
// 	put_tile(player->image, &coord, 0x80FFFFFF, map.ratio / 2);
// 	if (mlx_image_to_window(game->mlx, player->image, \
// 	player->position.x * map.ratio + 10 + map.ratio / 4, \
// 	player->position.y * map.ratio + 10  + map.ratio / 4) == -1)
// 		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
// 	mlx_set_instance_depth(player->image->instances, 11);
// 	return (EXIT_SUCCESS);
// }

int32_t	render_minimap(t_game_info *game)
{
	t_map_info		*map;
	t_coordinates	coord;

	coord.y = 0;
	map = &game->map;
	map->ratio = (int)calculate_resize(map);
	map->minimap = mlx_new_image(game->mlx, map->width * map->ratio, \
	map->height * map->ratio);
	while (map->layout[(int)coord.y] != NULL)
	{
		coord.x = 0;
		while (map->layout[(int)coord.y][(int)coord.x] != '\0')
		{
			if (map->layout[(int)coord.y][(int)coord.x] == '1')
				put_tile(map->minimap, &coord, 0xFFFFFFCC, map->ratio);
			else if (ft_strchr("0NESW", \
			map->layout[(int)coord.y][(int)coord.x]) != NULL)
				put_tile(map->minimap, &coord, 0xFFFFFF80, map->ratio);
			coord.x++;
		}
		coord.y++;
	}
	if (mlx_image_to_window(game->mlx, map->minimap, 10, 10) == -1)
		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
