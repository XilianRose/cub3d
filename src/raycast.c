/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/27 15:08:51 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/27 15:59:07 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_intersection(t_player_info *player)
{
	//
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
		ray->dir.x = player->dir.x + player->plane.x * ray->camera.x;
		ray->dir.y = player->dir.y + player->plane.y * ray->camera.x;
	}
}
