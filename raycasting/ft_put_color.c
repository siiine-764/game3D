/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 04:14:21 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 04:47:35 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_color_from_pos(mlx_texture_t *walli, int y, int x)
{
	int	index;

	if (x >= 0 && x < (int)walli->width && y >= 0 && y < (int)walli->height)
	{
		index = (walli->width * y + x) * walli->bytes_per_pixel;
		return (ft_pixel(walli->pixels[index], walli->pixels[index + 1],
				walli->pixels[index + 2], 255));
	}
	return (ft_pixel(0, 0, 0, 0));
}

void	put_color_sky(t_map *map)
{
	int	color;
	int	i;


	i = 0;
	color = 0;
	while (color < HEIGHT / 2)
	{
		i = 0;
		while (i <= WIDTH)
        {
			mlx_put_pixel(map->image, i, color,
				ft_pixel(34, 112, 147, 255));
            i++;
        }
		color++;
	}
	while (color < HEIGHT)
	{
		i = 0;
		while (i <= WIDTH)
        {
			mlx_put_pixel(map->image, i, color,
				ft_pixel(30, 39, 15, 255));
            i++;
        }
		color++;
	}
}

