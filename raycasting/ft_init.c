/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:09:24 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 05:32:40 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_hook(void *param)
{
    t_map *map = param;

    ft_movemnt(map);
    ft_first_draw(map->image_map);
    ft_first_draw(map->image);
    ft_draw(map);
    ft_draw_cub(map->image_map, 5, 5, map->x_p, map->y_p, 0xff0000ff);
    ft_start_raycasting(map); 
}

int ft_init(t_map *map)
{
    if (!(map->mlx = mlx_init(WIDTH, HEIGHT, "GAME 3D", true)))
    {
        printf("%s\n", mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    if (!(map->image_map = mlx_new_image(map->mlx, WIDTH, HEIGHT)))
    {
        mlx_close_window(map->mlx);
        printf("%s\n", mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    if (!(map->image = mlx_new_image(map->mlx, WIDTH, HEIGHT)))
    {
        mlx_close_window(map->mlx);
        printf("%s\n", mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    if (mlx_image_to_window(map->mlx, map->image, 0, 0) == -1)
    {
        mlx_close_window(map->mlx);
        printf("%s\n", mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    if (mlx_image_to_window(map->mlx, map->image_map, 0, 0) == -1)
    {
        mlx_close_window(map->mlx);
        printf("%s\n", mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    mlx_loop_hook(map->mlx, ft_hook, map);

    mlx_loop(map->mlx);
    mlx_terminate(map->mlx);
    return (EXIT_SUCCESS);
}