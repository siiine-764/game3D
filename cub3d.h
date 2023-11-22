/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:59:22 by mayache-          #+#    #+#             */
/*   Updated: 2023/11/22 21:59:24 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <MLX42/MLX42.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <string.h>

#define WIDTH 1512
#define HEIGHT 1512
#define SIZE_CUB 10
#define convert_degrees_radian M_PI / 180

typedef struct s_vector
{
    float x;
    float y;
} t_vector;

typedef struct s_texture	
{
	char		*key;
	char		*value;
	t_texture	*last;
    t_texture	*next;
}t_texture;

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

typedef struct s_garbage
{
	void		*address;
	t_garbage	*next;
	t_garbage	*last;
}t_garbage;

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
static bool	is_number(char *str);
int	       get_color(char *value);
void	fill_color(t_map *map, char *key, char *value);
void	color_checker(t_map *map);
static bool	top_bottom_closed(char *str);
static bool	is_closed(char *str);
static void	space_checker(char **map);
void	map_checker(char **map);
static void	add_to_textures(t_texture **t, char *key, char *value);
void	fill_tetxures_list(t_map *map, char *key, char *value);
void	textures_checker(t_map	*map);
bool	is_player(char c);
bool	contains_bad_char(char *str);
void	contains_player(char *str, int *p);
int	    tab_size(char **tab);
void	free_tab(char **tab);
char	*free_s1_join(char *s1, char *s2);
void	add_to_garbage(t_garbage **heap, void *address);
t_garbage	**g_heap(void);
void	empty_trash(t_garbage **heap);
void	throw_error(char *msg, t_garbage **heap);
static void	parse_texture_rgb(char *line, t_map *map);
static void	parse_line(char *line, int index, t_map *map, char **joined);
static void	read_map_helper(t_map *map, int fd, char *joined);
void	read_map(char *path, t_map *mapa);

#endif
