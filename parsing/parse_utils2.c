/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:09:12 by hben-mes          #+#    #+#             */
/*   Updated: 2023/11/23 12:09:12 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_script(char *scr, t_garb **top)
{
	if (top)
		empty_garbage(top);
	ft_putendl_fd(scr, 2);
	exit(1);
}

t_garb	**s_top(void)
{
	static t_garb	*top;

	return (&top);
}

void	garbage_join(t_garb **top, void *addr)
{
	t_garb	*node;

	node = malloc(sizeof(t_garb));
	if (!node)
		error_script("Error: error_in_malloc", NULL);
	node->addr = addr;
	node->nxt = NULL;
	node->lst = NULL;
	if (!*top)
	{
		*top = node;
		(*top)->nxt = NULL;
		(*top)->lst = node;
		return ;
	}
	(*top)->lst->nxt = node;
	(*top)->lst = node;
}

void	empty_garbage(t_garb **top)
{
	t_garb	*lead;
	t_garb	*tmp;

	if (!top || !*top)
		return ;
	lead = *top;
	while (lead)
	{
		tmp = lead;
		free(lead->addr);
		lead = lead->nxt;
		free(tmp);
	}
}
