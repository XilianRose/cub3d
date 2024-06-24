/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:50:32 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/24 13:19:44 by mstegema      ########   odam.nl         */
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
		return (false);
	else
		return (true);
}

static bool	contains_valid_chars(char *current, size_t i, t_game_info *game)
{
	if (ft_strchr(" 01NOSW", current[i]) == NULL)
		return (ft_printf(game->errme.map2), false);
	if (ft_strchr("NOSW", current[i]) && \
	game->player.orientation == 0)
		game->player.orientation = current[i];
	else if (ft_strchr("NOSW", current[i]) && \
	game->player.orientation != 0)
		return (ft_printf(game->errme.map3), false);
	return (true);
}

static bool	map_is_closed(char *above, char *current, char *below, size_t i)
{
	if (above == NULL || below == NULL)
	{
		if (ft_strchr("1 ", current[i]) == NULL)
			return (false);
	}
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
		if (contains_valid_chars(current, i, game) == false)
			return (false);
		if (map_is_closed(above, current, below, i) == false)
			return (ft_printf(game->errme.map1), false);
		i++;
	}
	game->map.height++;
	if (ft_strlen(current) > game->map.width)
		game->map.width = ft_strlen(current);
	if (save_layout(current, &game->map) == NULL)
	{
		my_freearray(game->map.layout);
		ft_printf(game->errme.mem0);
		return (false);
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
		return (ft_printf(errme->map0), MAP_NV);
	while (1)
	{
		above = curr;
		curr = below;
		below = get_next_line(game->file.fd);
		if (map_is_valid(above, curr, below, game) == false)
			return (free_3(above, curr, below), MAP_NV);
		if (below == NULL)
		{
			if (game->player.orientation == 0)
				return (ft_printf(errme->map4), free_3(above, curr, below), 1);
			return (MAP_OK);
		}
	}
	return (MAP_OK);
}

			// for (size_t i = 0; i < game->map.height; i++) 
			// {
			// 	printf("%s\n", game->map.layout[i]);
			// }