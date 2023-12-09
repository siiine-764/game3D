/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:08:57 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/09 07:48:46 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	text_fill(t_map *map, char *cue, char *val)
{
	if (val)
		if (val && !ft_strcmp(val, "NO"))
			map->no_png = cue;
	if (val && !ft_strcmp(val, "SO"))
		map->so_png = cue;
	if (val && !ft_strcmp(val, "EA"))
		map->ea_png = cue;
	if (val && !ft_strcmp(val, "WE"))
		map->we_png = cue;
}

void	check_textures(t_map *map)
{
	int			n[4];
	int			fd;
	t_texture	*tmp;

	tmp = map->textures;
	while (tmp)
	{
		fd = open(tmp->val, O_RDONLY);
		if (!ft_strcmp(tmp->cue, "NO") && fd != -1)
			n[0] = 1;
		else if (!ft_strcmp(tmp->cue, "SO") && fd != -1)
			n[1] = 1;
		else if (!ft_strcmp(tmp->cue, "WE") && fd != -1)
			n[2] = 1;
		else if (!ft_strcmp(tmp->cue, "EA") && fd != -1)
			n[3] = 1;
		close(fd);
		tmp = tmp->nxt;
	}
	if (!n[0] || !n[1] || !n[2] || !n[3])
		error_script("Error: something_wrong_in_textures", s_top());
}
