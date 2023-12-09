/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:42:10 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 03:30:15 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_draw_wall(t_map *map, float ray_nb)
{
    float wall_wide;
    float wall_height;
    float relative_x = fmod(map->ray_p_x, SIZE_CUB);
    float relative_y = fmod(map->ray_p_y, SIZE_CUB);
    
    mlx_texture_t *x = NULL;
    if (map->directin == 'N')
        x = map->no;
    else if (map->directin == 'S')
        x = map->so;
    else if (map->directin == 'W')
        x = map->we;
    else if (map->directin == 'E')
        x = map->ea;  
    wall_height = (HEIGHT / map->destonation) * SIZE_CUB;
    //map->fac = map->no->height/map->wall_height;


    if (map->directin == 'N' || map->directin == 'S')
        wall_wide = relative_x * x->width / SIZE_CUB;
    if (map->directin == 'W' || map->directin == 'E')
        wall_wide = relative_y * x->width / SIZE_CUB;
    // DDA(map, x1, y1, x2, y2);
    double		step = x->height / wall_height;
    float         txt_pos = 0;
    uint8_t		*pixelx;
	uint8_t		*pixeli;
    float         wall_y = (WIDTH - WIDTH / map->destonation * SIZE_CUB) / 2 - 1;
    
    while(wall_y < (WIDTH + wall_height) / 2)
    {
        txt_pos += step;
		if ((int) wall_y < WIDTH && wall_y > 0
			&& ((int)txt_pos * x->width + (int)wall_wide) < x->height
			* x->width)
		{
            pixelx = &x->pixels[(((int)txt_pos * x->width)
					+ (int)wall_wide) * x->bytes_per_pixel];
			pixeli = &map->image->pixels[(((int)wall_y * map->image->width)
					+ (int)ray_nb) * x->bytes_per_pixel];
			ft_memmove(pixeli, pixelx, x->bytes_per_pixel);
        }
        wall_y++;
    }
}

void    ft_cast(t_map *map, t_vector next_wall)
{
    int i;

    i = 0;
    while (i < map->size_y * map->size_x)
    {
        if (((int)(map->ray.y / SIZE_CUB) >= map->size_y || (int)(map->ray.x / SIZE_CUB) >= map->size_x)
            || ((int)(map->ray.y / SIZE_CUB) < 0 || (int)(map->ray.x / SIZE_CUB) < 0))
            break;
        if (map->mapa[(int)(map->ray.y / SIZE_CUB)][(int)(map->ray.x / SIZE_CUB)] == '1')
            break;
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

    ray_horizontal = ft_ray_casting_horizontal(map, dd);
    ray_vertical = ft_ray_casting_vertical(map, dd);
    destonation_vertical = sqrt(pow(map->x_p - ray_vertical.x, 2) + pow(map->y_p - ray_vertical.y, 2));
    destonation_horizontal = sqrt(pow(map->x_p - ray_horizontal.x, 2) + pow(map->y_p - ray_horizontal.y, 2));
    if (destonation_vertical < destonation_horizontal)
    {
        if(ray_vertical.x > map->x_p)
            map->directin = 'E';
        else
            map->directin = 'W';
        map->ray_p_x = ray_vertical.x;
        map->ray_p_y = ray_vertical.y;
        map->destonation = destonation_vertical;
        return (ray_vertical);
    }
    else
    {
        if(ray_horizontal.y > map->y_p)
            map->directin = 'S';
        else
            map->directin = 'N';
        map->ray_p_x = ray_horizontal.x;
        map->ray_p_y = ray_horizontal.y;
        map->destonation = destonation_horizontal;
        return (ray_horizontal);
    }
}

void ft_start_raycasting(t_map *map)
{
    t_vector ray;
    float point_of_view;
    float ray_nb;
    
    ray_nb = 0;
    point_of_view = map->p_rotation - 30;
    while (ray_nb < WIDTH)
    {
        if (point_of_view > 360)
            point_of_view -= 360;
        if (point_of_view < 0)
            point_of_view += 360;
        ray = ft_ray_casting(map, point_of_view);
        // DDA(map, map->x_p, map->y_p, ray.x, ray.y);
        map->destonation = map->destonation * cos((point_of_view - map->p_rotation) * (M_PI / 180.0));
        ft_draw_wall(map, ray_nb);
        ray_nb++;
        point_of_view += (60.0 / WIDTH);
    }
}