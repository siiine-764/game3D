/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:29:07 by mayache-          #+#    #+#             */
/*   Updated: 2023/11/06 16:14:37 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <MLX42/MLX42.h>
#include "libft/libft.h"
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



t_vector    ft_ray_casting_vertical(t_map *map, float dd);
t_vector    ft_ray_casting_horizontal(t_map *map, float dd);
t_vector ft_ray_casting(t_map *map, float dd);
void ft_draw_wall(t_map *map, float ray_nb);
void DDA(t_map *map,int X0, int Y0, int X1, int Y1);