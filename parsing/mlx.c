/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:20:09 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/06 22:41:14 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*my_mlx_xpm_file_to_img(t_map *map, char *path,
	int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx_ptr, path, width, height);
	if (!img)
		throw_error("Error: xpm_file_to_img_error", g_heap());
	return (img);
}


