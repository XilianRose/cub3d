/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_assets.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 17:36:30 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/11 18:09:49 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//add get_texture

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