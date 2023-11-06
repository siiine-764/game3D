/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:42:10 by mayache-          #+#    #+#             */
/*   Updated: 2023/11/06 16:16:42 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_draw_wall(t_map *map, float ray_nb)
{
    float x1;
    float y1;
    float x2;
    float y2;
    float x = ((HEIGHT / 2) / map->destonation) * SIZE_CUB;

    x1 = ray_nb;
    y1 = (HEIGHT / 2) - x;
    x2 = ray_nb;
    y2 = (HEIGHT / 2) + x;
    DDA(map, x1, y1, x2, y2);
}

void    ft_cast(t_map *map, t_vector next_wall)
{
    int i;

    i = 0;
    while (i < map->size_y * map->size_x)
    {
        if (((int)(map->ray.y / SIZE_CUB) >= map->size_y || (int)(map->ray.x / SIZE_CUB) >= map->size_x)
            || ((int)(map->ray.y / SIZE_CUB) < 0 || (int)(map->ray.x / SIZE_CUB) < 0))
        {
            break;
        }
        if (map->double_array_map[(int)(map->ray.y / SIZE_CUB)][(int)(map->ray.x / SIZE_CUB)] == '1')
        {
            break;
        }
        map->ray.x += next_wall.x;
        map->ray.y += next_wall.y;
        i++;
    }
}

t_vector    ft_ray_casting_horizontal(t_map *map, float dd)
{
    t_vector ray;
    t_vector next_wall;

    ray.x = 0;
    ray.y = 0;
    if (dd == 0 || dd == 180)
    {
        return (ray);
    }
    if (dd < 360 && dd > 180)
    {
        ray.y = (int)(map->y_p / SIZE_CUB) * SIZE_CUB - 0.0001;
        next_wall.y = SIZE_CUB * (-1);
    }
    else
    {
        ray.y = (int)(map->y_p / SIZE_CUB) * SIZE_CUB + SIZE_CUB;
        next_wall.y = SIZE_CUB;
    }
    ray.x = -(map->y_p - ray.y) / tan(dd * convert_degrees_radian) + map->x_p;
    next_wall.x = next_wall.y / tan(dd * convert_degrees_radian);
    map->ray = ray;
    ft_cast(map, next_wall);
    return map->ray;
}

t_vector    ft_ray_casting_vertical(t_map *map, float dd)
{
    t_vector ray;
    t_vector next_wall;

    ray.x = 0;
    ray.y = 0;
    if (dd == 90 || dd == 270)
    {
        return (ray);
    }
    if (dd > 90 && dd < 270)
    {
        ray.x = (int)(map->x_p / SIZE_CUB) * SIZE_CUB - 0.0001;
        next_wall.x = SIZE_CUB * (-1);
    }
    else
    {
        ray.x = (int)(map->x_p / SIZE_CUB) * SIZE_CUB + SIZE_CUB;
        next_wall.x = SIZE_CUB;
    }
    ray.y = -(map->x_p - ray.x) * tan(dd * convert_degrees_radian) + map->y_p;
    next_wall.y = next_wall.x * tan(dd * convert_degrees_radian);
    map->ray = ray;
    ft_cast(map, next_wall);
    return map->ray;
}

t_vector ft_ray_casting(t_map *map, float dd)
{
    t_vector ray_vertical;
    t_vector ray_horizontal;
    float destonation_vertical;
    float destonation_horizontal;

    // printf("dd = %f\n", dd);
    ray_horizontal = ft_ray_casting_horizontal(map, dd);
    ray_vertical = ft_ray_casting_vertical(map, dd);
    destonation_vertical = sqrt(pow(map->x_p - ray_vertical.x, 2) + pow(map->y_p - ray_vertical.y, 2));
    destonation_horizontal = sqrt(pow(map->x_p - ray_horizontal.x, 2) + pow(map->y_p - ray_horizontal.y, 2));
    if (destonation_vertical < destonation_horizontal)
    {
        map->destonation = destonation_vertical;
        return (ray_vertical);
    }
    else
    {
        map->destonation = destonation_horizontal;
        return (ray_horizontal);
    }
}