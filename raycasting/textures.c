/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:07:22 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 05:38:35 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void	get_textures(t_map *map)
{
	char	*str;

	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	str = ft_strtrim(&map->textures->val[0], "\n");
	map->no = mlx_load_png(str);
	free(str);
	str = ft_strtrim("textures/wall_3.png", "\n");
	map->so = mlx_load_png(str);
	free(str);
	str = ft_strtrim("textures/wall_2.png", "\n");
	map->ea = mlx_load_png(str);
	free(str);
	str = ft_strtrim("textures/wall_1.png", "\n");
	map->we = mlx_load_png(str);
	free(str);

}

void put_textures(t_map *map, mlx_texture_t *x, float ray_nb)
{
	double		step;
    float		txt_pos;
    uint8_t		*pixelx;
	uint8_t		*pixeli;
    float		wall_y;
    
	txt_pos = 0;
	step = x->height / map->wall_height;
	wall_y = (WIDTH - WIDTH / map->destonation * SIZE_CUB) / 2 - 1;
    while(wall_y < (WIDTH + map->wall_height) / 2)
    {
        txt_pos += step;
		if ((int) wall_y < WIDTH && wall_y > 0
			&& ((int)txt_pos * x->width + (int)map->wall_width) < x->height
			* x->width)
		{
            pixelx = &x->pixels[(((int)txt_pos * x->width)
					+ (int)map->wall_width) * x->bytes_per_pixel];
			pixeli = &map->image->pixels[(((int)wall_y * map->image->width)
					+ (int)ray_nb) * x->bytes_per_pixel];
			ft_memmove(pixeli, pixelx, x->bytes_per_pixel);
        }
        wall_y++;
    }
}

t_vector ft_util(t_map *map, float d_vertical, float d_horizontal,
 t_vector ray_vertic, t_vector ray_horizon)
{
	if (d_vertical < d_horizontal)
    {
        if(ray_vertic.x > map->x_p)
            map->directin = 'E';
        else
            map->directin = 'W';
        map->ray_p_x = ray_vertic.x;
        map->ray_p_y = ray_vertic.y;
        map->destonation = d_vertical;
        return (ray_vertic);
    }
    else
    {
        if(ray_horizon.y > map->y_p)
            map->directin = 'S';
        else
            map->directin = 'N';
        map->ray_p_x = ray_horizon.x;
        map->ray_p_y = ray_horizon.y;
        map->destonation = d_horizontal;
        return (ray_horizon);
    }
}