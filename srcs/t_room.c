/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/05 18:17:48 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	create_room(char *p_name, t_room_state p_state, int x, int y)
{
	t_room	result;

	result.name = ft_strdup(p_name);
	result.x = x;
	result.y = y;
	result.previous = NULL;
	result.active = FALSE;
	result.distance = UINT_MAX;
	result.state = p_state;
	result.parent = malloc_list(100);
	result.children = malloc_list(100);
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
	size_t j;

	ft_printf("{%3s} - [%6b] - [%12u] - {%5s} - {%9s} -> [total : %u] - ", room->name, room->active, room->distance, (room->previous == NULL ? "null" : room->previous->name), state_str(room->state), room_nb_link_active(room));
	j = 0;
	while (j < room->children->size)
	{
		if (j != 0)
			ft_printf(" - ");
		print_link(list_at(room->children, j));
		j++;
	}
	ft_printf("\n");
}

void add_room_link(t_room *parent, t_room *children)
{
	t_link	*p_link;

	p_link = malloc_link(parent, children);
	list_push_back(parent->children, p_link);
	list_push_back(children->parent, p_link);

	p_link = malloc_link(children, parent);
	list_push_back(parent->parent, p_link);
	list_push_back(children->children, p_link);
}

size_t room_nb_link_active(t_room *room)
{
	size_t	nb;
	size_t	j;

	nb = 0;
	j = 0;
	while (j < room->children->size)
	{
		if (((t_link *)list_at(room->children, j))->flow != 0)
			nb++;
		j++;
	}
	return (nb);
}
