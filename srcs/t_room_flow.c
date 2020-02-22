/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/22 17:54:39 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	room_flow_parent(t_room *room)
{
	t_link	*link;
	int		nb;
	size_t	j;

	nb = 0;
	j = 0;
	while (j < room->links->size)
	{
		link = list_at(room->links, j);
		if (room == link->children)
			nb += link->flow;
		j++;
	}
	return (nb);
}

int	room_flow_children(t_room *room)
{
	t_link	*link;
	int		nb;
	size_t	j;

	nb = 0;
	j = 0;
	while (j < room->links->size)
	{
		link = list_at(room->links, j);
		if (room == link->parent)
			nb += link->flow;
		j++;
	}
	return (nb);
}

int	room_flow_total(t_room *room)
{
	t_link	*link;
	int		nb;
	size_t	j;

	nb = 0;
	j = 0;
	while (j < room->links->size)
	{
		link = list_at(room->links, j);
		if (link->parent == room)
			nb += link->flow;
		else
			nb -= link->flow;
		j++;
	}
	return (nb);
}
