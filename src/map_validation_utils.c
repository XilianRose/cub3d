/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:50:32 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/18 15:16:32 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_texture(char *row, t_map_info *map, t_error *errme, \
mlx_texture_t **texture)
{
	if (*texture != NULL)
	{
		my_freestr(row);
		free_map_struct(map);
		exit_wrapper(errme->map6);
	}
	*texture = get_texture(row, errme, texture);
}

void	handle_color(char *row, t_map_info *map, t_error *errme, \
uint32_t color)
{
	if (color != 0)
	{
		my_freestr(row);
		free_map_struct(map);
		exit_wrapper(errme->map6);
	}
	color = get_color(row, errme);
}

void	save_elements(char *row, t_map_info *map, t_error *errme)
{
	if (ft_strnstr(row, "NO ", 3))
		handle_texture(row, map, errme, &map->no_texture);
	else if (ft_strnstr(row, "SO ", 3))
		handle_texture(row, map, errme, &map->so_texture);
	else if (ft_strnstr(row, "WE ", 3))
		handle_texture(row, map, errme, &map->we_texture);
	else if (ft_strnstr(row, "EA ", 3))
		handle_texture(row, map, errme, &map->ea_texture);
	else if (ft_strnstr(row, "C ", 2))
		handle_color(row, map, errme, map->c_color);
	else if (ft_strnstr(row, "F ", 2))
		handle_color(row, map, errme, map->f_color);
	my_freestr(row);
	return ;
}

char	**save_layout(char *row, t_map_info *map)
{
	char	**temp;

	temp = NULL;
	if (row == NULL)
		return (NULL);
	temp = (char **)realloc_arr(map->layout, map->height + 1);
	if (temp == NULL)
		return (NULL);
	temp[map->height - 1] = row;
	map->layout = temp;
	return (map->layout);
}

bool	elements_not_null(t_map_info *map)
{
	if (map->no_texture == NULL || map->so_texture == NULL || \
	map->we_texture == NULL || map->ea_texture == NULL || \
	map->c_color == 0 || map->f_color == 0)
		return (false);
	return (true);
}
