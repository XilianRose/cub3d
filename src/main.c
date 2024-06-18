/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:14:01 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/18 18:17:16 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_file_info	file;
	t_map_info	map;
	t_error		errme;

	file.argc = argc;
	file.argv = argv;
	error_message(&errme);
	if (file_validation(&file, &errme) == FILE_NV)
		exit (FILE_NV);
	initialize_map_info(&map);
	ft_printf("hi\n"); //here
	if (map_validation(&file, &map, &errme) == MAP_NV)
		exit(MAP_NV);
	return (1);
}
