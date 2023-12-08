/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:07:22 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/08 23:12:16 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void	get_textures(t_map *var)
{
	char	*str;

	// var->no = NULL;
	// var->so = NULL;
	// var->ea = NULL;
	// var->we = NULL;
	str = ft_strtrim(&var->textures->cue[0], "\n");
	var->no = mlx_load_png(&var->textures->cue[0]);
	// free(str);
	str = ft_strtrim(&var->textures->cue[1], "\n");
	var->so = mlx_load_png(&var->textures->cue[1]);
	// free(str);
	str = ft_strtrim(&var->textures->cue[2], "\n");
	var->ea = mlx_load_png(&var->textures->cue[2]);
	// free(str);
	str = ft_strtrim(&var->textures->cue[3], "\n");
	var->we = mlx_load_png(&var->textures->cue[3]);
	// free(str);

}