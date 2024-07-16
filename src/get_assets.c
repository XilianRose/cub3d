/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_assets.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 17:36:30 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/16 16:47:29 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	get_pixel_color(mlx_texture_t *texture, int x, int y)
{
	uint32_t	color;
	uint8_t		*pixel;
	int			offset;

	offset = (y * texture->width + x) * 4;
	pixel = &texture->pixels[offset];
	color = get_rgba(pixel[0], pixel[1], pixel[2], pixel[3]);
	return (color);
}

mlx_texture_t	*get_texture(char *str, t_error *errme)
{
	mlx_texture_t	*texture;
	char			*temp;

	temp = ft_strtrim(str + 3, "\n");
	if (!temp)
	{
		my_freestr(str);
		return (exit_wrapper(errme->mem0), NULL);
	}
	printf("%s", temp);
	texture = mlx_load_png(temp);
	if (!texture)
	{
		my_freestr(str);
		my_freestr(temp);
		return (exit_wrapper(errme->mlx0), NULL);
	}
	return (my_freestr(temp), texture);
}

uint32_t	get_color(char *str, t_error *errme)
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
