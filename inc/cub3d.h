/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 16:26:12 by mstegema      #+#    #+#                 */
/*   Updated: 2024/07/12 14:49:43 by mstegema      ########   odam.nl         */
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

#define EW_SIDE 0
#define NS_SIDE 1

#define WHITE50 0xFFFFFF80
#define WHITE80 0xFFFFFFCC

typedef struct s_coordinates
{
	double				x;
	double				y;
}	t_coordinates;

typedef struct s_ray
{
	t_coordinates	dir;
	t_coordinates	camera;
	t_coordinates	plane;
	t_coordinates	side_dist;
	t_coordinates	delta_dist;
	int				side;
	int				line_start;
	unsigned int	line_end;
	double			wall_dist;
}	t_ray;

typedef struct s_player_info
{
	mlx_image_t		*image;
	char			orientation;
	t_coordinates	dir;
	t_coordinates	position;
	t_coordinates	step;
	t_ray			ray;
}	t_player_info;

typedef struct s_map_info
{
	size_t			width;
	size_t			height;
	char			**layout;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	int				f_color;
	int				c_color;
	mlx_image_t		*minimap;
	int				ratio;
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
	char			*map5;
	char			*mem0;
	char			*mlx0;
}	t_error;

typedef struct s_game_info
{
	t_error			errme;
	t_file_info		file;
	t_map_info		map;
	t_player_info	player;
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_image_t		*fps_image;
	double			time;
}	t_game_info;

/* map validation */
int				map_validation(t_game_info *game, t_error *errme);
bool			elements_not_null(t_map_info *map);
void			save_elements(char *row, t_map_info *map, t_error *errme);
char			**save_layout(char *row, t_map_info *map);

/* get assets*/
uint32_t		get_color(char	*str, t_error *errme);
mlx_texture_t	*get_texture(char *str, t_error *errme);

/* window management */
int32_t			window_management(t_game_info *game);

/* rendering */
int32_t			render_minimap(t_game_info *game);
int32_t			render_player(t_game_info *game);
int32_t			render_stats(t_game_info *game);
void			render_view(t_game_info *game, mlx_image_t *image, int x);
void			put_line(int x, t_game_info *game, unsigned int color, \
				mlx_image_t *image);
void			put_tile(mlx_image_t *image, t_coordinates *coord, \
				unsigned int color, int ratio);
double			calculate_resize(t_map_info *map);

/* raycast */
void			raycast(t_player_info *player, t_map_info *map, \
				mlx_image_t *image, t_game_info *game);

/* player movement*/
void			move_up(t_game_info *game);
void			move_down(t_game_info *game);
void			move_left(t_game_info *game);
void			move_right(t_game_info *game);
void			rotate_left(t_game_info *game);
void			rotate_right(t_game_info *game);

/* init */
void			initialize_map_info(t_game_info *game);
void			initialize_ray_info(t_game_info *game);

/* memory */
void			free_map_struct(t_map_info *map);
char			**realloc_arr(char **ptr, size_t size);

/* utils */
void			error_message(t_error *errme);
int32_t			mlx_error_wrapper(mlx_t	*mlx);
void			exit_wrapper(char *str);
