/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:38:46 by hben-mes          #+#    #+#             */
/*   Updated: 2023/11/30 18:49:02 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>
#include <MLX42/MLX42.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <string.h>

#define WIDTH 1512
#define HEIGHT 1512
#define SIZE_CUB 10
#define convert_degrees_radian M_PI / 180

typedef struct s_garbage	t_garbage;
typedef struct s_texture	t_texture;
typedef struct s_mlx        t_mlx;

typedef struct s_vector
{
    float x;
    float y;
} t_vector;

typedef struct s_garbage
{
	void		*address;
	t_garbage	*next;
	t_garbage	*last;
}t_garbage;

typedef struct s_texture	
{
	char		*key;
	char		*value;
    t_texture	*next;
	t_texture	*last;
}t_texture;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}t_mlx;

typedef struct s_map
{
    mlx_image_t* image;
    mlx_image_t* image_map;

    t_texture	*textures;
	int			celling_color;
	int			floor_color;

    char		**mapa;
    char **double_array_map;
    float x_p;
    float y_p;
    int width;
    int height;
    int color;
    mlx_t* mlx;
    float p_rotation;
    float destonation;
    int size_x;
    int size_y;
    t_vector ray;
} t_map;

enum e_keys
{
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125
};

/// functions init ////
int ft_init(t_map *map);

/// functions raycasting ////
void ft_start_raycasting(t_map *map);
t_vector    ft_ray_casting_vertical(t_map *map, float dd);
t_vector    ft_ray_casting_horizontal(t_map *map, float dd);
t_vector ft_ray_casting(t_map *map, float dd);
void DDA(mlx_image_t *image, int X0, int Y0, int X1, int Y1);

/// functions movement ////
void    ft_movement(t_map *map);
void ft_w(t_map *map);
void ft_s(t_map *map);
void ft_a(t_map *map);
void ft_d(t_map *map);

/// functions draw ////
void ft_draw_cub(mlx_image_t *map, int width, int height, int x_start, int y_start, int color);
// void ft_first_draw(t_map *map);
void ft_draw(t_map *map);
void ft_draw_wall(t_map *map, float ray_nb);
void ft_first_draw(mlx_image_t *image);

/// functions position player ////
void    ft_position_player(t_map *map);
void ft_n_p(t_map *map, int x, int y);
void ft_s_p(t_map *map, int x, int y);
void ft_e_p(t_map *map, int x, int y);
void ft_w_p(t_map *map, int x, int y);

//parsing
int     ft_num  (char *str);
int	    color_put(char *value);
void	color_load(t_map *map, char *key, char *value);
void	check_color(t_map *map);
int	    check_top_bottom(char *str);
int    	ft_close(char *str);
void	check_space(char **map);
void	check_map(char **map);
void	text_add(t_texture **t, char *key, char *value);
void	text_fill(t_map *map, char *key, char *value);
void	check_textures(t_map	*map);
int	    player_button(char c);
int 	char_hold(char *str);
void	player_hold(char *str, int *p);
int	    ft_strcmp(char *s1, char *s2);
int	    tab_size(char **tab);
void	free_tab(char **tab);
char	*free_s1_join(char *s1, char *s2);
void	add_to_garbage(t_garbage **heap, void *address);
t_garbage	**g_heap(void);
void	empty_trash(t_garbage **heap);
void	throw_error(char *msg, t_garbage **heap);
void	texture_parse(char *line, t_map *map);
void	line_parsing(char *line, int index, t_map *map, char **joined);
void	assist_map_reader(t_map *map, int fd, char *joined);
void	map_reader(char *path, t_map *mapa);

#endif
