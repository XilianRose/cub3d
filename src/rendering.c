/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/28 11:14:01 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/18 14:16:33 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_line(int x, t_game_info *game, mlx_texture_t *texture, \
mlx_image_t *image)
{
	t_ray			*ray;
	unsigned int	i;

	ray = &game->player.ray;
	i = HEIGHT - 1;
	while (i >= ray->line_end)
	{
		mlx_put_pixel(image, x, i, game->map.f_color);
		i--;
	}
	i = 0;
	while ((int) i < ray->line_start)
	{
		mlx_put_pixel(image, x, i, game->map.c_color);
		i++;
	}
	draw_wall(x, &game->player, texture, image);
	return ;
}

void	render_view(t_game_info *game, mlx_image_t *image, int x)
{
	if (game->player.ray.side == EW_SIDE)
	{
		if (game->player.ray.dir.x > 0)
			put_line(x, game, game->map.ea_texture, image);
		else
			put_line(x, game, game->map.we_texture, image);
	}
	else
	{
		if (game->player.ray.dir.y > 0)
			put_line(x, game, game->map.so_texture, image);
		else
			put_line(x, game, game->map.no_texture, image);
	}
}

int32_t	render_stats(t_game_info *game)
{
	char	*fps;
	char	*temp;

	temp = ft_itoa(1 / game->time);
	fps = ft_strjoin("FPS: ", temp);
	game->fps_image = mlx_put_string(game->mlx, fps, 10, HEIGHT - 20);
	my_freestr(temp);
	my_freestr(fps);
	if (!game->fps_image)
		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
	mlx_set_instance_depth(game->fps_image->instances, 12);
	return (EXIT_SUCCESS);
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
	player->image = mlx_new_image(game->mlx, map.ratio / 2, map.ratio / 2);
	put_tile(player->image, &coord, 0x80FFFFFF, map.ratio / 2);
	if (mlx_image_to_window(game->mlx, player->image, \
	player->position.x * map.ratio + 10, \
	player->position.y * map.ratio + 10) == -1)
		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
	mlx_set_instance_depth(player->image->instances, 11);
	return (EXIT_SUCCESS);
}

int32_t	render_minimap(t_game_info *game)
{
	t_coordinates	coord;

	coord.y = 0;
	game->map.ratio = (int)calculate_resize(&game->map);
	game->map.minimap = mlx_new_image(game->mlx, game->map.width * \
	game->map.ratio, game->map.height * game->map.ratio);
	while (game->map.layout[(int)coord.y] != NULL)
	{
		coord.x = 0;
		while (game->map.layout[(int)coord.y][(int)coord.x] != '\0')
		{
			if (game->map.layout[(int)coord.y][(int)coord.x] == '1')
				put_tile(game->map.minimap, &coord, WHITE80, game->map.ratio);
			else if (ft_strchr("0NESW", \
			game->map.layout[(int)coord.y][(int)coord.x]) != NULL)
				put_tile(game->map.minimap, &coord, WHITE50, game->map.ratio);
			coord.x++;
		}
		coord.y++;
	}
	if (mlx_image_to_window(game->mlx, game->map.minimap, 10, 10) == -1)
		return (mlx_error_wrapper(game->mlx), EXIT_FAILURE);
	mlx_set_instance_depth(game->map.minimap->instances, 6);
	return (EXIT_SUCCESS);
}
