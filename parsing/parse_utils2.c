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

void	error_script(char *msg, t_garbage **top)
{
	if (top)
		empty_garbage(top);
	ft_putendl_fd(msg, 2);
	exit(1);
}

t_garbage	**s_top(void)
{
	static	t_garbage	*top;

	return (&top);
}

void	garbage_join(t_garbage **top, void *address)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (!new)
		error_script("Error: malloc failed", NULL);
	new->address = address;
	new->next = NULL;
	new->last = NULL;
	if (!*top)
	{
		*top = new;
		(*top)->next = NULL;
		(*top)->last = new;
		return ;
	}
	(*top)->last->next = new;
	(*top)->last = new;
}

void	empty_garbage(t_garbage **top)
{
	t_garbage	*tmp;
	t_garbage	*head;

	if (!top || !*top)
		return ;
	head = *top;
	while (head)
	{
		tmp = head;
		free(head->address);
		head = head->next;
		free(tmp);
	}
}
