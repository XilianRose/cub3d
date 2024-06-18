/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:50:32 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/18 16:01:40 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	contains_elements(t_file_info *file, t_map_info *map, \
t_error *errme)
{
	char	*row;

	row = "";
	while (elements_not_null == false && row != NULL)
	{
		save_elements(row, map);
		row = get_next_line(file->fd);
	}
	if (elements_not_null == false)
		return (free_map_struct(map), false);
	else
		return (true);
}

static bool	contains_valid_chars(char *current, int i, t_map_info *map)
{
	if (ft_strchr(" 01NOSW", current[i]) == false)
		return (ft_printf("Error\nmap contains invalid characters\n"), false);
	if (ft_strchr("NOSW", current[i]) == true && \
	map->player->orientation == '0')
		map->player->orientation = current[i];
	if (ft_strchr("NOSW", current[i]) == true && \
	map->player->orientation != '0')
		return (ft_printf("Error\nmap contains more than 1 player \
		starting positions\n"), false);
	return (true);
}

static bool	map_is_closed(char *above, char *current, char *below, int i)
{
	if (current[i] == ' ' && (ft_strchr("1 ", current[i - 1]) == false \
	|| ft_strchr("1 ", current[i + 1]) == false))
		return (ft_printf("Error\nmap is not properly closed\n"), false);
	if (ft_strlen(current) > ft_strlen(above) && current[i] > \
	ft_strlen(above) && current[i] != '1')
		return (ft_printf("Error\nmap is not properly closed\n"), false);
	if (ft_strlen(current) > ft_strlen(below) && current[i] > \
	ft_strlen(below) && current[i] != '1')
		return (ft_printf("Error\nmap is not properly closed\n"), false);
	return (true);
}

static bool	map_is_valid(char *above, char *current, char *below, \
	t_map_info *map)
{
	int		i;

	i = 0;
	map->rows++;
	while (current[i] == ' ')
		i++;
	if (current[i] != '1' || current[ft_strlen(current) != '1'])
		return (false);
	while (i < ft_strlen(current))
	{
		if (above == NULL || below == NULL)
		{
			if (ft_strchr("1 ", current[i]) == false)
				return (false);
		}
		else
		{
			if (contains_valid_chars(current, i, map) == false || \
			map_is_closed(above, current, below, i) == false)
				return (false);
		}
	}
	return (true);
}

int	map_validation(t_file_info *file, t_map_info *map, t_error *errme)
{
	char	*above;
	char	*current;
	char	*below;

	above = NULL;
	current = NULL;
	below = NULL;
	if (contains_elements(file, map, errme) != true)
		exit_wrapper(errme->map0);
	while (1)
	{
		my_freestr(above);
		above = current;
		current = below;
		below = get_next_line(file->fd);
		if (map_is_valid(above, current, below, map) == false)
			exit (0);
		if (below == NULL)
		{
			my_freestr(current);
			my_freestr(above);
			break ;
		}
	}
	return (1);
}
