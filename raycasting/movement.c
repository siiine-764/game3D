/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:24:37 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/04 22:10:29 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_w(t_map *map)
{
    map->y_p += sin(map->p_rotation * convert_degrees_radian);
    map->x_p += cos(map->p_rotation * convert_degrees_radian);
    if (map->mapa[(int)(map->y_p / SIZE_CUB)][(int)(map->x_p / SIZE_CUB)] == '1')
    {
        map->y_p -= sin(map->p_rotation * convert_degrees_radian);
        map->x_p -= cos(map->p_rotation * convert_degrees_radian);
    }
}

void ft_s(t_map *map)
{
    map->y_p -= sin(map->p_rotation * convert_degrees_radian);
    map->x_p -= cos(map->p_rotation * convert_degrees_radian);
    if (map->mapa[(int)(map->y_p / SIZE_CUB)][(int)(map->x_p / SIZE_CUB)] == '1')
    {
        map->y_p += sin(map->p_rotation * convert_degrees_radian);
        map->x_p += cos(map->p_rotation * convert_degrees_radian);
    }
}

void ft_a(t_map *map)
{       
    map->y_p -= cos(map->p_rotation * convert_degrees_radian);
    map->x_p += sin(map->p_rotation * convert_degrees_radian);
    if (map->mapa[(int)(map->y_p / SIZE_CUB)][(int)(map->x_p / SIZE_CUB)] == '1')
    {
        map->y_p += cos(map->p_rotation * convert_degrees_radian);
        map->x_p -= sin(map->p_rotation * convert_degrees_radian);
    }
}

void ft_d(t_map *map)
{
    map->y_p += cos(map->p_rotation * convert_degrees_radian);
    map->x_p -= sin(map->p_rotation * convert_degrees_radian);
    if (map->mapa[(int)(map->y_p / SIZE_CUB)][(int)(map->x_p / SIZE_CUB)] == '1')
    {
        map->y_p -= cos(map->p_rotation * convert_degrees_radian);
        map->x_p += sin(map->p_rotation * convert_degrees_radian);
    }
}

void    ft_movement(t_map *map)
{
    if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(map->mlx);
    if (map->p_rotation > 360)
        map->p_rotation -= 360;
    if (map->p_rotation < 0)
        map->p_rotation += 360;
    if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
        map->p_rotation -= 1;
    if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
        map->p_rotation += 1;
    if (mlx_is_key_down(map->mlx, MLX_KEY_W))
        ft_w(map);
    if (mlx_is_key_down(map->mlx, MLX_KEY_S))
        ft_s(map);
    if (mlx_is_key_down(map->mlx, MLX_KEY_A))
        ft_a(map);
    if (mlx_is_key_down(map->mlx, MLX_KEY_D))
        ft_d(map);
}