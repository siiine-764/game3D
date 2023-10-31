/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:29:07 by mayache-          #+#    #+#             */
/*   Updated: 2023/10/31 23:24:31 by mayache-         ###   ########.fr       */
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
#define SIZE_CUB 30
#define convert_degrees_radian M_PI / 180

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
} t_map;
