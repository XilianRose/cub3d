/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:32:23 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/12 12:40:54 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	errme->mlx0 = "Error\nloading texture from .png failed\n";
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
