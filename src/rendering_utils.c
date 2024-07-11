/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/04 10:52:04 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/11 17:34:13 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_tile(mlx_image_t *image, t_coordinates *coord, \
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
