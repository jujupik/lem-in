/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acces_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:09:05 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/22 18:09:23 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*get_next_room(t_room *room)
{
	t_link	*link;
	t_room	*next;
	size_t	i;

	i = 0;
	while (i < room->links->size)
	{
		link = list_at(room->links, i);
		next = (link->children != room ? link->children : link->parent);
		if (next->distance == room->distance - 1)
			return (next);
		i++;
	}
	return (NULL);
}

t_room	*find_next_room(t_room *room)
{
	t_link	*link;
	t_room	*next;
	size_t	i;

	i = 0;
	while (i < room->links->size)
	{
		link = list_at(room->links, i);
		next = (link->children == room ? link->parent : link->children);
		if ((link->flow == 1 && link->parent == room) ||
			(link->flow == -1 && link->children == room))
			return (next);
		i++;
	}
	return (NULL);
}
