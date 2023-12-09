/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:42:10 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 10:27:19 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_cast(t_map *map, t_vector next_wall)
{
	int	i;

	i = 0;
	while (i < map->size_y * map->size_x)
	{
		if (((int)(map->ray.y / SIZE_CUB) >= map->size_y || (int)(map->ray.x
			/ SIZE_CUB) >= map->size_x) || ((int)(map->ray.y
					/ SIZE_CUB) < 0 || (int)(map->ray.x / SIZE_CUB) < 0))
			break ;
		if (map->mapa[(int)(map->ray.y / SIZE_CUB)][(int)(map->ray.x
				/ SIZE_CUB)] == '1')
			break ;
		map->ray.x += next_wall.x;
		map->ray.y += next_wall.y;
		i++;
	}
}

t_vector	ft_ray_casting_horizontal(t_map *map, float dd)
{
	t_vector	ray;
	t_vector	next_wall;

	ray.x = 0;
	ray.y = 0;
	if (dd == 0 || dd == 180)
		return (ray);
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
	ray.x = -(map->y_p - ray.y) / tan(dd * CRT_DEGRS_RADIAN / 180) + map->x_p;
	next_wall.x = next_wall.y / tan(dd * CRT_DEGRS_RADIAN / 180);
	map->ray = ray;
	ft_cast(map, next_wall);
	return (map->ray);
}

t_vector	ft_ray_casting_vertical(t_map *map, float dd)
{
	t_vector	ray;
	t_vector	next_wall;

	ray.x = 0;
	ray.y = 0;
	if (dd == 90 || dd == 270)
		return (ray);
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
	ray.y = -(map->x_p - ray.x) * tan(dd * CRT_DEGRS_RADIAN / 180) + map->y_p;
	next_wall.y = next_wall.x * tan(dd * CRT_DEGRS_RADIAN / 180);
	map->ray = ray;
	ft_cast(map, next_wall);
	return (map->ray);
}

t_vector	ft_ray_casting(t_map *map, float dd)
{
	t_vector		ray_vertic;
	t_vector		ray_horizon;
	t_ver_horizon	ver_horizon;
	float			d_vertical;
	float			d_horizontal;

	ray_horizon = ft_ray_casting_horizontal(map, dd);
	ray_vertic = ft_ray_casting_vertical(map, dd);
	d_vertical = sqrt(pow(map->x_p - ray_vertic.x, 2) + pow(map->y_p
				- ray_vertic.y, 2));
	d_horizontal = sqrt(pow(map->x_p - ray_horizon.x, 2) + pow(map->y_p
				- ray_horizon.y, 2));
	ver_horizon.d_horizontal = d_horizontal;
	ver_horizon.d_vertical = d_vertical;
	ver_horizon.ray_horizon = ray_horizon;
	ver_horizon.ray_vertic = ray_vertic;
	return (ft_util(map, ver_horizon));
}

void	ft_start_raycasting(t_map *map)
{
	t_vector	ray;
	float		point_of_view;
	float		ray_nb;

	ray_nb = 0;
	point_of_view = map->p_rotation - 30;
	while (ray_nb < WIDTH)
	{
		if (point_of_view > 360)
			point_of_view -= 360;
		if (point_of_view < 0)
			point_of_view += 360;
		ray = ft_ray_casting(map, point_of_view);
		map->destonation = map->destonation * cos((point_of_view
					- map->p_rotation) * (M_PI / 180.0));
		ft_draw_wall(map, ray_nb);
		ray_nb++;
		point_of_view += (60.0 / WIDTH);
	}
}
