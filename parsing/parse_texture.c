/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:08:57 by hben-mes          #+#    #+#             */
/*   Updated: 2023/11/23 12:08:57 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	text_add(t_texture **text, char *val, char *cue)
{
	t_texture	*node;

	node = malloc(sizeof(t_texture));
	if (!node)
		error_script("Error: error_in_malloc", s_top());
	garbage_join(s_top(), node);
	node->cue = cue;
	node->val = val;
	node->nxt = NULL;
	node->lst = NULL;
	if (!*text)
	{
		*text = node;
		(*text)->lst = node;
		(*text)->nxt = NULL;
	}
	else
	{
		(*text)->lst->nxt = node;
		node->lst = (*text)->lst;
		(*text)->lst = node;
	}
}

void	text_fill(t_map *map, char *val, char *cue)
{
	if (cue && (!ft_strcmp(cue, "NO") || !ft_strcmp(cue, "SO")
			|| !ft_strcmp(cue, "WE") || !ft_strcmp(cue, "EA")))
		text_add(&map->textures, cue, val);
}

void	check_textures(t_map *map)
{
	t_texture	*tmp;
	int			fd;
	int	c[4] = {0, 0, 0, 0};

	tmp = map->textures;
	while (tmp)
	{
		fd = open(tmp->val, O_RDONLY);
		if (!ft_strcmp(tmp->cue, "NO") && fd != -1)
			c[0] = 1;
		else if (!ft_strcmp(tmp->cue, "SO") && fd != -1)
			c[1] = 1;
		else if (!ft_strcmp(tmp->cue, "WE") && fd != -1)
			c[2] = 1;
		else if (!ft_strcmp(tmp->cue, "EA") && fd != -1)
			c[3] = 1;
		close(fd);
		tmp = tmp->nxt;
	}
	if (!c[0] || !c[1] || !c[2] || !c[3])
		error_script("Error: something_wrong_in_textures", s_top());
}