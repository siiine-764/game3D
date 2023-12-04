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

void	error_script(char *msg, t_garbage **heap)
{
	if (heap)
		empty_garbage(heap);
	ft_putendl_fd(msg, 2);
	exit(1);
}

t_garbage	**s_top(void)
{
	static t_garbage	*heap;

	return (&heap);
}

void	garbage_join(t_garbage **heap, void *address)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (!new)
		error_script("Error: malloc failed", NULL);
	new->address = address;
	new->next = NULL;
	new->last = NULL;
	if (!*heap)
	{
		*heap = new;
		(*heap)->next = NULL;
		(*heap)->last = new;
		return ;
	}
	(*heap)->last->next = new;
	(*heap)->last = new;
}

void	empty_garbage(t_garbage **heap)
{
	t_garbage	*tmp;
	t_garbage	*head;

	if (!heap || !*heap)
		return ;
	head = *heap;
	while (head)
	{
		tmp = head;
		free(head->address);
		head = head->next;
		free(tmp);
	}
}
