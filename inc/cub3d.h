/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:26:12 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/29 15:50:55 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fcntl.h>
#include <stdlib.h>
#include "../libft/inc/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define FILE_OK 0
#define FILE_NV 1

#define MAP_OK 0
#define MAP_NV 1

#define WIDTH 1600
#define HEIGHT 900
#define TILE_SIZE 8

typedef struct s_coordinates
{
	double				x;
	double				y;
}	t_coordinates;

typedef struct s_ray
{
	t_coordinates	position;
	t_coordinates	dir;
	t_coordinates	camera;
}	t_ray;

typedef struct s_player_info
{
	mlx_image_t		*image;
	char			orientation;
	t_coordinates	position;
	t_coordinates	dir;
	t_coordinates	plane;
	t_ray			ray;
}	t_player_info;

typedef struct s_map_info
{
	size_t			width;
	size_t			height;
	char			**layout;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	char			*f_color;
	char			*c_color;
	mlx_image_t		*minimap;
}	t_map_info;

typedef struct s_file_info
{
	int				argc;
	char			**argv;
	int				fd;
}	t_file_info;

typedef struct s_error
{
	char			*file0;
	char			*file1;
	char			*file2;
	char			*map0;
	char			*map1;
	char			*map2;
	char			*map3;
	char			*map4;
	char			*mem0;
}	t_error;

typedef struct s_game_info
{
	t_error			errme;
	t_file_info		file;
	t_map_info		map;
	t_player_info	player;
	mlx_t			*mlx;
	mlx_image_t		*image;
}	t_game_info;

/* map validation */
int		map_validation(t_game_info *game, t_error *errme);
void	save_elements(char *row, t_map_info *map);
char	**save_layout(char *row, t_map_info *map);
bool	elements_not_null(t_map_info *map);

/* window management */
int32_t	window_management(t_game_info *game);

/* rendering */
int32_t	render_minimap(t_game_info *game);
int32_t	render_player(t_game_info *game);

/* free */
void	free_map_struct(t_map_info *map);
void	free_3(char *str1, char *str2, char *str3);

/* utils */
char	**realloc_arr(char **ptr, size_t size);
void	initialize_map_info(t_game_info *game);
void	error_message(t_error *errme);
int32_t	mlx_error_wrapper(mlx_t	*mlx);
void	exit_wrapper(char *str);
