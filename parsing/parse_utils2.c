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

void	error_script(char *t, t_garb **top)
{
	if (top)
		empty_garbage(top);
	ft_putendl_fd(t, 2);
	exit(1);
}

t_garb	**s_top(void)
{
	static	t_garb	*top;

	return (&top);
}

void	garbage_join(t_garb **top, void *address)
{
	t_garb	*new;

	new = malloc(sizeof(t_garb));
	if (!new)
		error_script("Error: error_in_malloc", NULL);
	new->addr = address;
	new->nxt = NULL;
	new->lst = NULL;
	if (!*top)
	{
		*top = new;
		(*top)->nxt = NULL;
		(*top)->lst = new;
		return ;
	}
	(*top)->lst->nxt = new;
	(*top)->lst = new;
}

void	empty_garbage(t_garb **top)
{
	t_garb	*tmp;
	t_garb	*head;

	if (!top || !*top)
		return ;
	head = *top;
	while (head)
	{
		tmp = head;
		free(head->addr);
		head = head->nxt;
		free(tmp);
	}
}
