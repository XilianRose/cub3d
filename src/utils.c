/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:32:23 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/24 13:25:36 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*realloc_arr(void *ptr, size_t size)
{
	void	*res;
	size_t	old_size;

	res = NULL;
	if (ptr == NULL)
		return (ft_calloc(1, size));
	else if (size == 0)
		return (my_freearray(ptr), NULL);
	res = ft_calloc(1, size);
	if (!res)
		return (NULL);
	old_size = ft_strlen((char *)ptr);
	if (size > old_size)
		ft_memmove(res, ptr, old_size);
	else
	{
		ft_memmove(res, ptr, size);
		((char *)res)[size - 1] = '\0';
	}
	return (res);
}

void	initialize_map_info(t_game_info *game)
{
	game->map.width = 0;
	game->map.height = 0;
	game->map.layout = NULL;
	game->map.no_texture = NULL;
	game->map.so_texture = NULL;
	game->map.we_texture = NULL;
	game->map.ea_texture = NULL;
	game->map.f_color = NULL;
	game->map.c_color = NULL;
	game->player.orientation = 0;
	game->player.position.x = 0;
	game->player.position.y = 0;
}

void	error_message(t_error *errme)
{
	errme->file0 = "Error\nplease give one filename as argument\n";
	errme->file1 = "Error\nnot a '.cub' map description file\n";
	errme->file2 = "Error\nencountered problem while opening the file\n";
	errme->map0 = "Error\nscene description is missing 1 or more elements\n";
	errme->map1 = "Error\nmap is not properly closed\n";
	errme->map2 = "Error\nmap contains invalid characters\n";
	errme->map3 = "Error\nmap contains more than 1 player starting positions\n";
	errme->map4 = "Error\nmap contains no player starting positions\n";
	errme->mem0 = "Error\nmalloc failed\n";
	return ;
}

void	exit_wrapper(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
