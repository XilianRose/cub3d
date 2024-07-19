/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/28 11:14:01 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/19 13:32:06 by mstegema      ########   odam.nl         */
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
