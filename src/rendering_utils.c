/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/04 10:52:04 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/04 13:14:00 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_resize(t_map_info *map)
{
	double	quarter_screen_width;
	double	quarter_screen_height;
	double	layout_width;
	double	layout_height;

	quarter_screen_width = (double) WIDTH / 4;
	quarter_screen_height = (double) HEIGHT / 4;
	layout_width = (double) map->width;
	layout_height = (double) map->height;
	if (quarter_screen_width / map->width < quarter_screen_height / map->height)
		return (quarter_screen_width / map->width);
	else
		return (quarter_screen_height / map->height);
}

