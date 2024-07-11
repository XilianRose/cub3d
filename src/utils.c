/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:32:23 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/11 15:42:23 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**realloc_arr(char **ptr, size_t size)
{
	char	**res;
	size_t	old_size;

	res = NULL;
	old_size = 0;
	if (ptr == NULL)
		return ((char **)ft_calloc(1, sizeof(char *) * (size)));
	else if (size == 0)
		return (my_freearray(ptr), NULL);
	res = (char **)ft_calloc(1, sizeof(char *) * (size));
	if (!res)
		return (NULL);
	while (ptr[old_size] != NULL)
		old_size++;
	old_size += 1;
	if (size > old_size)
		ft_memmove(res, ptr, sizeof(char *) * (old_size));
	else
	{
		ft_memmove(res, ptr, sizeof(char *) * (size));
		res[size - 1] = 0;
	}
	return (free(ptr), res);
}

static void	initialize_ray_info_2(t_game_info *game)
{
	if (game->player.orientation == 'E')
	{
		game->player.ray.plane.x = 0;
		game->player.ray.plane.y = 1;
		game->player.dir.x = 1;
		game->player.dir.y = 0;
	}
	if (game->player.orientation == 'W')
	{
		game->player.ray.plane.x = 0;
		game->player.ray.plane.y = -1;
		game->player.dir.x = -1;
		game->player.dir.y = 0;
	}
	return ;
}

void	initialize_ray_info(t_game_info *game)
{
	if (game->player.orientation == 'N')
	{
		game->player.ray.plane.x = 1;
		game->player.ray.plane.y = 0;
		game->player.dir.x = 0;
		game->player.dir.y = -1;
	}
	if (game->player.orientation == 'S')
	{
		game->player.ray.plane.x = -1;
		game->player.ray.plane.y = 0;
		game->player.dir.x = 0;
		game->player.dir.y = 1;
	}
	initialize_ray_info_2(game);
	return ;
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
	game->time = 0;
	return ;
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
	errme->map5 = "Error\nmap contains invalid colorcodes\n";
	errme->mem0 = "Error\nmalloc failed\n";
	return ;
}

int32_t	mlx_error_wrapper(mlx_t	*mlx)
{
	if (mlx)
		mlx_close_window(mlx);
	ft_putstr_fd((char *) mlx_strerror(mlx_errno), 2);
	return (EXIT_FAILURE);
}

void	exit_wrapper(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
