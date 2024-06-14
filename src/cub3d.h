/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:26:12 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/14 16:59:31 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fcntl.h>
#include <stdlib.h>
#include "../libft/inc/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define FILE_OK 1
#define FILE_NV 0

#define MAP_OK 1
#define MAP_NV 0

typedef struct s_file_info
{
	int		argc;
	char	**argv;
	int		fd;
}	t_file_info;

typedef struct s_map_info
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*f_color;
	char	*c_color;
}	t_map_info;

typedef struct s_game_info
{
	mlx_t	*mlx;
}	t_map_info;

typedef struct s_error
{
	char	*file0;
	char	*file1;
	char	*file2;
}	t_error;
