/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:33:21 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 10:38:03 by mayache-         ###   ########.fr       */
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
	str = ft_strtrim(map->ea_png, "\n");
	map->no = mlx_load_png(str);
	free(str);
	str = ft_strtrim(map->we_png, "\n");
	map->so = mlx_load_png(str);
	free(str);
	str = ft_strtrim(map->no_png, "\n");
	map->ea = mlx_load_png(str);
	free(str);
	str = ft_strtrim(map->so_png, "\n");
	map->we = mlx_load_png(str);
	free(str);
}

void	put_textures(t_map *map, mlx_texture_t *x, float ray_nb)
{
	double	step;
	float	txt_pos;
	uint8_t	*pixelx;
	uint8_t	*pixeli;
	float	wall_y;

	txt_pos = 0;
	step = x->height / map->wall_height;
	wall_y = (WIDTH - WIDTH / map->destonation * SIZE_CUB) / 2 - 1;
	while (wall_y < (WIDTH + map->wall_height) / 2)
	{
		txt_pos += step;
		if ((int)wall_y < WIDTH && wall_y > 0 && ((int)txt_pos * x->width
				+ (int)map->wall_width) < x->height * x->width)
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

t_vector	ft_util(t_map *map, t_ver_horizon ver_horizon)
{
	if (ver_horizon.d_vertical < ver_horizon.d_horizontal)
	{
		if (ver_horizon.ray_vertic.x > map->x_p)
			map->directin = 'E';
		else
			map->directin = 'W';
		map->ray_p_x = ver_horizon.ray_vertic.x;
		map->ray_p_y = ver_horizon.ray_vertic.y;
		map->destonation = ver_horizon.d_vertical;
		return (ver_horizon.ray_vertic);
	}
	else
	{
		if (ver_horizon.ray_horizon.y > map->y_p)
			map->directin = 'S';
		else
			map->directin = 'N';
		map->ray_p_x = ver_horizon.ray_horizon.x;
		map->ray_p_y = ver_horizon.ray_horizon.y;
		map->destonation = ver_horizon.d_horizontal;
		return (ver_horizon.ray_horizon);
	}
}

void	ft_draw_wall(t_map *map, float ray_nb)
{
	float			relative_x;
	float			relative_y;
	mlx_texture_t	*x;

	x = NULL;
	relative_y = fmod(map->ray_p_y, SIZE_CUB);
	relative_x = fmod(map->ray_p_x, SIZE_CUB);
	if (map->directin == 'N')
		x = map->no;
	else if (map->directin == 'S')
		x = map->so;
	else if (map->directin == 'W')
		x = map->we;
	else if (map->directin == 'E')
		x = map->ea;
	map->wall_height = (HEIGHT / map->destonation) * SIZE_CUB;
	if (map->directin == 'N' || map->directin == 'S')
		map->wall_width = relative_x * x->width / SIZE_CUB;
	if (map->directin == 'W' || map->directin == 'E')
		map->wall_width = relative_y * x->width / SIZE_CUB;
	put_textures(map, x, ray_nb);
}
