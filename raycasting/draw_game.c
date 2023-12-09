/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:36:25 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 09:58:43 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_first_draw(mlx_image_t *image)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(image, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	ft_draw_cub(mlx_image_t *image, int x_start,
		int y_start, int color)
{
	int	i;
	int	y;

	i = x_start;
	while (i < (int)(x_start + SIZE_CUB))
	{
		y = y_start;
		while (y < (int)(y_start + SIZE_CUB))
		{
			if (y < HEIGHT && i < WIDTH && y > 0 && i > 0)
				mlx_put_pixel(image, i, y, color);
			y++;
		}
		i++;
	}
}

void	ft_mini_draw(t_map *map, int x, int y)
{
	if (map->mapa[y][x] == '1')
		ft_draw_cub(map->image_map, x * SIZE_CUB, y
			* SIZE_CUB, 0x800080ff);
	if (map->mapa[y][x] == '0' || map->mapa[y][x] == 'N' ||
		map->mapa[y][x] == 'S' || map->mapa[y][x] == 'E' ||
		map->mapa[y][x] == 'W')
		ft_draw_cub(map->image_map, x * SIZE_CUB, y
			* SIZE_CUB, 0xffffffff);
}

void	ft_draw(t_map *map)
{
	int	x;
	int	y;
	int	max;

	x = 0;
	y = 0;
	max = 0;
	while (map->mapa[y] != NULL)
	{
		x = 0;
		while (map->mapa[y][x] != '\0')
		{
			ft_mini_draw(map, x, y);
			x++;
		}
		if (max < x)
			max = x;
		y++;
	}
	map->size_x = max;
	map->size_y = y;
	put_color_sky(map);
}

void	ft_draw_cub1(t_map *map, int hei, int color)
{
	int	i;
	int	y;

	i = map->x_p;
	while (i < (int)(map->x_p + hei))
	{
		y = map->y_p;
		while (y < (int)(map->y_p + hei))
		{
			if (y < HEIGHT && i < WIDTH && y > 0 && i > 0)
				mlx_put_pixel(map->image_map, i, y, color);
			y++;
		}
		i++;
	}
}
