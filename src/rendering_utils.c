/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/04 10:52:04 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/11 15:45:28 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	get_color(char	*str, t_error *errme)
{
	char	**char_array;
	int		int_array[3];
	int		res;
	int		i;

	res = 0;
	i = 0;
	char_array = ft_split(str + 2, ',');
	if (!char_array)
		return (exit_wrapper(errme->mem0), res);
	while (i < 3)
	{
		if (char_array[i] == NULL)
			return (my_freearray(char_array), exit_wrapper(errme->mem0), res);
		int_array[i] = ft_atoi(char_array[i]);
		i++;
	}
	if (int_array[0] < 0 || int_array[0] > 255 || int_array[1] < 0 || \
	int_array[1] > 255 || int_array[2] < 0 || int_array[2] > 255)
		return (my_freearray(char_array), exit_wrapper(errme->map5), res);
	res = get_rgba(int_array[0], int_array[1], int_array[2], 255);
	return (my_freearray(char_array), res);
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
