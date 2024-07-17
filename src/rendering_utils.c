/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/04 10:52:04 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/17 15:05:19 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "math.h"

static int	calculate_texture_x(t_player_info *player, mlx_texture_t *texture)
{
	t_ray	*ray;
	double	wall_x;
	int		tex_x;

	ray = &player->ray;
	wall_x = 0;
	tex_x = 0;
	if (ray->side == 0)
		wall_x = player->position.y + ray->wall_dist * ray->dir.y;
	else
		wall_x = player->position.x + ray->wall_dist * ray->dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->dir.x > 0) || \
	(ray->side == 1 && ray->dir.y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	draw_wall(int x, t_player_info *player, mlx_texture_t *texture, \
mlx_image_t *image)
{
	unsigned int	y;
	uint32_t		color;
	int				pixel_coordinates[2];
	double			step;
	double			tex_tile_pos;

	y = player->ray.line_start;
	step = 1.0 * (texture->height) / \
	(player->ray.line_end - player->ray.line_start);
	tex_tile_pos = (player->ray.line_start - HEIGHT / 2 + \
	(player->ray.line_end - player->ray.line_start) / 2) * step;
	pixel_coordinates[0] = calculate_texture_x(player, texture);
	while (y <= player->ray.line_end)
	{
		pixel_coordinates[1] = (int)tex_tile_pos & (texture->height - 1);
		tex_tile_pos += step;
		color = get_pixel_color(texture, pixel_coordinates[0], \
		pixel_coordinates[1]);
		mlx_put_pixel(image, x, y, color);
		y++;
	}
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

	quarter_screen_width = (double) WIDTH / 4;
	quarter_screen_height = (double) HEIGHT / 4;
	if (quarter_screen_width / map->width < quarter_screen_height / map->height)
		return (quarter_screen_width / map->width);
	else
		return (quarter_screen_height / map->height);
}
