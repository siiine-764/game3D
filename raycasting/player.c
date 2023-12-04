/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:56:28 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/04 19:51:18 by hben-mes         ###   ########.fr       */
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
    int y = 0;
    int x = 0;
    while (map->double_array_map[y])
    {
        x = 0;
        while (map->double_array_map[y][x])
        {
            if (map->double_array_map[y][x] == 'N')
                ft_n_p(map, x, y);
            else if (map->double_array_map[y][x] == 'S')
                ft_s_p(map, x, y);
            else if (map->double_array_map[y][x] == 'E')
                ft_e_p(map, x, y);
            else if (map->double_array_map[y][x] == 'W')
                ft_w_p(map, x, y);
            x++;
        }
        y++;
    }
}