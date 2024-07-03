/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/27 15:08:51 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/03 17:23:28 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	calculate_height_distance(t_player_info *player, int draw_pixels[2])
{
	int	line_height;

	if (player->ray.side == NS_SIDE)
		player->ray.wall_dist = player->ray.side_dist.x - player->ray.delta_dist.x;
	else
		player->ray.wall_dist = player->ray.side_dist.y - player->ray.delta_dist.y;
	line_height = (int) HEIGHT / player->ray.wall_dist;
	draw_pixels[0] = (-line_height / 2) + (HEIGHT / 2);
	if (draw_pixels[0] < 0)
		draw_pixels[0] = 0;
	draw_pixels[1] = (line_height / 2) + (HEIGHT / 2);
	if (draw_pixels[1] >= HEIGHT)
		draw_pixels[1] = HEIGHT - 1;
	return ;
}

void	calculate_step(t_player_info *player)
{
	if (player->ray.dir.x < 0)
	{
		player->step.x = -1;
		player->ray.side_dist.x = (player->position.x - \
		(int)player->position.x) * player->ray.delta_dist.x;
	}
	else
	{
		player->step.x = 1;
		player->ray.side_dist.x = ((int)player->position.x + 1.0 \
		- player->position.x) * player->ray.delta_dist.x;
	}
	if (player->ray.dir.y < 0)
	{
		player->step.y = -1;
		player->ray.side_dist.y = (player->position.y - \
		(int)player->position.y) * player->ray.delta_dist.y;
	}
	else
	{
		player->step.y = 1;
		player->ray.side_dist.y = ((int)player->position.y + \
		1.0 - player->position.y) * player->ray.delta_dist.y;
	}
}

void	calculate_ray_direction(t_player_info *player)
{
	t_ray	*ray;
	int		x;

	ray = &player->ray;
	x = 0;
	while (x < WIDTH)
	{
		ray->camera.x = 2 * x / (double) WIDTH - 1;
		ray->dir.x = ray->dir.x + ray->plane.x * ray->camera.x;
		ray->dir.y = ray->dir.y + ray->plane.y * ray->camera.x;
	}
	if (ray->dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

void	dda(t_player_info *player, t_map_info *map)
{
	int		map_x;
	int		map_y;
	bool	hit;

	map_x = (int)player->position.x;
	map_y = (int)player->position.y;
	hit = false;
	while (hit == false)
	{
		if (player->ray.side_dist.x < player->ray.side_dist.y)
		{
			player->ray.side_dist.x += player->ray.delta_dist.x;
			map_x += player->step.x;
			player->ray.side = NS_SIDE;
		}
		else
		{
			player->ray.side_dist.y += player->ray.delta_dist.y;
			map_y += player->step.y;
			player->ray.side = EW_SIDE;
		}
		if (map->layout[map_y][map_x] == '1')
			hit = true;
	}
}

void	raycast(t_player_info *player, t_map_info *map, mlx_image_t *image)
{
	int				x;
	int				draw_pixels[2];
	unsigned int	color;

	x = 0;
	color = 0xFF000000;
	while (x < WIDTH)
	{
		calculate_ray_direction(player);
		calculate_step(player);
		dda(player, map);
		calculate_height_distance(player, draw_pixels);
		if (player->ray.side == EW_SIDE)
			color = color / 2;
		put_line(x, draw_pixels, color, image);
		x++;
	}
}
