/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:14:01 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/27 15:01:01 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @todo
 *
 * window management
 *
 * DDA algorithm (raycasting)
 * 	Calculate ray direction
 * 	Calculate delta distance
 * 	Calculate step & initial side distance
 * 	DDA
 * 	Calculate wall height
 *
 * rendering
 * 	(mlx image functionality)
 *
 * Player movement
 */

static int	file_validation(t_file_info *file, t_error *errme)
{
	if (file->argc != 2)
		exit_wrapper(errme->file0);
	if (my_strendstr(file->argv[1], ".cub") == NULL)
		exit_wrapper(errme->file1);
	file->fd = open(file->argv[1], O_RDONLY);
	if (file->fd < 0)
		return (perror("Error\n"), close(file->fd), FILE_NV);
	return (FILE_OK);
}

int	main(int argc, char **argv)
{
	t_game_info	game;

	game.file.argc = argc;
	game.file.argv = argv;
	error_message(&game.errme);
	if (file_validation(&game.file, &game.errme) == FILE_NV)
		return (FILE_NV);
	initialize_map_info(&game);
	if (map_validation(&game, &game.errme) == MAP_NV)
		return (free_map_struct(&game.map), EXIT_FAILURE);
	if (window_management(&game) == EXIT_FAILURE)
		return (free_map_struct(&game.map), EXIT_FAILURE);
	return (free_map_struct(&game.map), EXIT_SUCCESS);
}
