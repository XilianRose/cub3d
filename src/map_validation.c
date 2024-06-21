/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:50:32 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/21 12:10:50 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	contains_elements(t_file_info *file, t_map_info *map)
{
	char	*row;

	row = get_next_line(file->fd);
	while (elements_not_null(map) == false && row != NULL)
	{
		save_elements(row, map);
		row = get_next_line(file->fd);
	}
	my_freestr(row);
	if (elements_not_null(map) == false)
		return (free_map_struct(map), false);
	else
		return (true);
}

static bool	contains_valid_chars(char *current, size_t i, t_game_info *game)
{
	if (ft_strchr(" 01NOSW", current[i]) == NULL)
		return (ft_printf(game->errme.map2), false);
	if (ft_strchr("NOSW", current[i]) && \
	game->map.player.orientation == '0')
		game->map.player.orientation = current[i];
	if (ft_strchr("NOSW", current[i]) && \
	game->map.player.orientation != '0')
		return (ft_printf(game->errme.map3), false);
	return (true);
}

static bool	map_is_closed(char *above, char *current, char *below, size_t i)
{
	if (current[i] == '0' && (current[i - 1] == ' ' \
	|| current[i + 1] == ' '))
		return (false);
	if (above && ft_strlen(current) > ft_strlen(above) \
	&& i > ft_strlen(above) && current[i] != '1')
		return (false);
	if (below && ft_strlen(current) > ft_strlen(below) \
	&& i > ft_strlen(below) && current[i] != '1')
		return (false);
	if (above && current[i] == '0' && above[i] == ' ')
		return (false);
	if (below && current[i] == '0' && below[i] == ' ')
		return (false);
	return (true);
}

static bool	map_is_valid(char *above, char *current, char *below, \
	t_game_info *game)
{
	size_t	i;

	i = 0;
	if (current == NULL)
		return (true);
	while (i < ft_strlen(current) - 2)
	{
		if (above == NULL || below == NULL)
		{
			if (ft_strchr("1 ", current[i]) == NULL || \
			map_is_closed(above, current, below, i) == false)
				return (ft_printf(game->errme.map1, false));
		}
		else
		{
			if (contains_valid_chars(current, i, game) == false || \
			map_is_closed(above, current, below, i) == false)
				return (ft_printf(game->errme.map1, false));
		}
		i++;
	}
	return (true);
}

int	map_validation(t_game_info *game, t_error *errme)
{
	char	*above;
	char	*curr;
	char	*below;

	above = NULL;
	curr = NULL;
	below = NULL;
	if (contains_elements(&game->file, &game->map) != true)
		exit_wrapper(errme->map0);
	while (1)
	{
		my_freestr(above);
		above = curr;
		curr = below;
		below = get_next_line(game->file.fd);
		if (map_is_valid(above, curr, below, game) == false)
			return (free_3(above, curr, below), 0);
		if (below == NULL)
		{
			if (game->map.player.orientation == 0)
				return (ft_printf(errme->map4), free_3(above, curr, below), 0);
			return (free_3(above, curr, below), 1);
		}
	}
	return (1);
}
