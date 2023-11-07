/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:29:07 by mayache-          #+#    #+#             */
/*   Updated: 2023/11/07 17:35:13 by mayache-         ###   ########.fr       */
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

typedef struct s_map
{
    mlx_image_t* image;
    mlx_image_t* image_map;
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

#endif