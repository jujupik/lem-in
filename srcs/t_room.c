/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/06 15:53:01 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t g_name_len = 1;

t_room	create_room(char *p_name, t_room_state p_state, int x, int y)
{
	t_room	result;

	result.name = ft_strdup(p_name);
	if (ft_strlen(result.name) > g_name_len)
		g_name_len = ft_strlen(result.name);
	result.x = x;
	result.y = y;
	result.previous = NULL;
	result.active = FALSE;
	result.distance = UINT_MAX;
	result.state = p_state;
	result.links = malloc_list(100);
	return (result);
}

t_room	*malloc_room(char *p_name, t_room_state p_state, int x, int y)
{
	t_room	*result;

	result = (t_room *)malloc(sizeof(t_room));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_room");
	*result = create_room(p_name, p_state, x, y);
	return (result);
}

void	destroy_room(t_room to_destroy)
{
	free(to_destroy.name);
}

void	free_room(t_room *to_free)
{
	destroy_room(*to_free);
	free(to_free);
}

void print_room(t_room *room)
{
	t_link	*link;
	size_t	j;
	size_t	first;

	first = 0;
	ft_printf("{%*s} - [%6b] - [%12u] - {%5s} - {%9s} -> [total : %2d (%2d / %2d)] - ", g_name_len, room->name, room->active, room->distance, (room->previous == NULL ? "null" : room->previous->name), state_str(room->state), room_flow_total(room), room_flow_children(room), room_flow_parent(room));
	j = 0;
	while (j < room->links->size)
	{
		link = list_at(room->links, j);
		if (room != link->children)
		{
			if (j != first)
				ft_printf(" - ");
			print_link(room, link);
		}
		else
			first++;
		j++;
	}
	ft_printf("\n");
}

void add_room_link(t_room *parent, t_room *children)
{
	t_link	*p_link;

	p_link = malloc_link(parent, children);
	list_push_back(parent->links, p_link);
	list_push_back(children->links, p_link);
}

int room_flow_parent(t_room *room)
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

int room_flow_children(t_room *room)
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

int room_flow_total(t_room *room)
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
