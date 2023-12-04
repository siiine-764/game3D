/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:56:28 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/04 22:09:43 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_n_p(t_map *map, int x, int y)
{               
    map->x_p = x * SIZE_CUB;
    map->y_p = y * SIZE_CUB;
    map->p_rotation = 270;
}

void ft_s_p(t_map *map, int x, int y)
{
    map->x_p = x * SIZE_CUB;
    map->y_p = y * SIZE_CUB;
    map->p_rotation = 90;
}

void ft_e_p(t_map *map, int x, int y)
{
    map->x_p = x * SIZE_CUB;
    map->y_p = y * SIZE_CUB;
    map->p_rotation = 0;
}

void ft_w_p(t_map *map, int x, int y)
{
    map->x_p = x * SIZE_CUB;
    map->y_p = y * SIZE_CUB;
    map->p_rotation = 180;
}

void    ft_position_player(t_map *map)
{
    (void)map;
    int y = 0;
    int x = 0;
    while (map->mapa[y])
    {
        x = 0;
        while (map->mapa[y][x])
        {
            if (map->mapa[y][x] == 'N')
                ft_n_p(map, x, y);
            else if (map->mapa[y][x] == 'S')
                ft_s_p(map, x, y);
            else if (map->mapa[y][x] == 'E')
                ft_e_p(map, x, y);
            else if (map->mapa[y][x] == 'W')
                ft_w_p(map, x, y);
            x++;
        }
        y++;
    }
}