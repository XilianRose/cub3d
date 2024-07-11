/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/04 10:52:04 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/11 18:08:26 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//change to accept texture
void	put_line(int x, t_game_info *game, unsigned int color, \
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
	i = ray->line_start;
	while (i <= ray->line_end)
	{
		mlx_put_pixel(image, x, i, color); //change to accept texture
		i++;
	}
	return ;
}

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
