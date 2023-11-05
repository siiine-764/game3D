/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:42:10 by mayache-          #+#    #+#             */
/*   Updated: 2023/11/03 16:02:06 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_ray_casting(t_map *map)
{
    t_vector ray;

    ray.x = 0;
    ray.y = 0;


    if (map->p_rotation > 360 && map->p_rotation > 180)
    {
        ray.y = (int)(map->y_p / SIZE_CUB) * SIZE_CUB;
        ray.x = (int)(map->x_p  - SIZE_CUB);
    }
    else
    {
        ray.y = (int)(map->y_p / SIZE_CUB) * SIZE_CUB + SIZE_CUB;
    }








    
    while ()
    {
        /* code */
    }
    
}