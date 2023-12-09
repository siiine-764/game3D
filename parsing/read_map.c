/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 07:00:26 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/09 07:00:32 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_parse(char *l, t_map *map)
{
	int		i;
	char	*val;
	char	*cue;

	i = 0;
	while (l[i] && l[i] != ' ')
		i++;
	cue = ft_substr(l, 0, i);
	garbage_join(s_top(), cue);
	if (cue && (ft_strcmp(cue, "NO") && ft_strcmp(cue, "SO") && ft_strcmp(cue,
				"EA") && ft_strcmp(cue, "WE") && ft_strcmp(cue, "C")
			&& ft_strcmp(cue, "F")))
		error_script("Error: something_wrong_in_textures", s_top());
	while (l[i] && l[i] == ' ')
		i++;
	val = ft_substr(l, i, ft_strlen(l) - i - 1);
	if (!cue || !val)
		error_script("Error: error_in_malloc", s_top());
	garbage_join(s_top(), val);
	text_fill(map, val, cue);
	color_load(map, val, cue);
}

void	line_parsing(char *l, int ind, t_map *map, char **str)
{
	static bool	flag;

	if (ind < 6)
		texture_parse(l, map);
	else
	{
		if (l[0] != '\n')
			flag = true;
		if (flag && l[0] == '\n')
		{
			free(*str);
			error_script("Error: empty_line_found", s_top());
		}
		*str = join_free(*str, l);
	}
}

void	assist_map_reader(t_map *map, int fd, char *str)
{
	int	i;

	i = 0;
	close(fd);
	map->mapa = ft_split(str, '\n', NULL);
	free(str);
	if (!map->mapa || !map->mapa[0])
		error_script("Error: the_map_is_empty", s_top());
	while (map->mapa[i])
		garbage_join(s_top(), map->mapa[i++]);
	garbage_join(s_top(), map->mapa);
}

void	map_reader(char *p, t_map *map)
{
	int		fd;
	int		i;
	char	*l;
	char	*str;

	fd = open(p, O_RDONLY);
	if (fd == -1)
		error_script("Error: error_in_the_file", NULL);
	i = 0;
	str = NULL;
	l = get_next_line(fd);
	while (l)
	{
		if (i < 6 && *l == '\n')
		{
			free(l);
			l = get_next_line(fd);
			continue ;
		}
		line_parsing(l, i, map, &str);
		free(l);
		i++;
		l = get_next_line(fd);
	}
	assist_map_reader(map, fd, str);
}
