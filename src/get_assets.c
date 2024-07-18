/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_assets.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 17:36:30 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/18 14:49:16 by mstegema      ########   odam.nl         */
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

mlx_texture_t	*get_texture(char *str, t_error *errme, mlx_texture_t **texture)
{
	char			*temp;
	int				fd;

	temp = ft_strtrim(str + 3, " \n\t");
	if (!temp)
		return (my_freestr(temp), exit_wrapper(errme->mem0), NULL);
	fd = open(temp, O_RDONLY);
	if (fd < 0)
	{
		*texture = NULL;
		my_freestr(temp);
		my_freestr(str);
		return (exit_wrapper(errme->mlx0), NULL);
	}
	close(fd);
	*texture = mlx_load_png(temp);
	if (!texture)
	{
		my_freestr(str);
		my_freestr(temp);
		return (exit_wrapper(errme->mlx0), NULL);
	}
	return (my_freestr(temp), *texture);
}

static bool	is_valid_color(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (ft_strlen(str) > 11)
		return (false);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ',')
			i++;
		else
			return (false);
		if (str[i] == ',')
			count++;
	}
	if (count > 2)
		return (false);
	return (true);
}

uint32_t	get_color(char *str, t_error *errme)
{
	char	**char_array;
	int		int_array[3];
	int		res;
	int		i;

	res = 0;
	i = 0;
	if (is_valid_color(str) == false)
		return (exit_wrapper(errme->map5), res);
	char_array = ft_split(str + 2, ',');
	if (!char_array)
		return (exit_wrapper(errme->mem0), res);
	while (i < 3)
	{
		if (int_array[i] < 0 || int_array[i] > 255)
			return (my_freearray(char_array), exit_wrapper(errme->map5), res);
		int_array[i] = ft_atoi(char_array[i]);
		i++;
	}
	res = get_rgba(int_array[0], int_array[1], int_array[2], 255);
	return (my_freearray(char_array), res);
}
