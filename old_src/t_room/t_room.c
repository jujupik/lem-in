/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 08:00:03 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	create_room(char *p_name, t_room_state p_status, int x, int y)
{
	t_room	result;

	result.name = ft_strdup(p_name);
	result.x = x;
	result.y = y;
	result.status = p_status;
	result.children = malloc_room_list(500);
	result.parent = malloc_room_list(500);
	result.distance = UINT_MAX;
	result.occuped = FALSE;
	result.fourmis = NULL;
	result.nb_use = 0;
	return (result);
}

t_room	*malloc_room(char *p_name, t_room_state p_status, int x, int y)
{
	t_room	*result;

	result = (t_room *)malloc(sizeof(t_room));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_room");
	*result = create_room(p_name, p_status, x, y);
	return (result);
}

void	destroy_room(t_room to_destroy)
{
	free(to_destroy.name);
	free_room_list(to_destroy.parent);
	free_room_list(to_destroy.children);
}

void	free_room(t_room *to_free)
{
	destroy_room(*to_free);
	free(to_free);
}

void	room_add_link(t_room *a, t_room *b)
{
	size_t	i;
	BOOL	found;

	i = 0;
	found = FALSE;
	while (i < a->parent->size && found == FALSE)
	{
		if (t_room_list_at(a->parent, i) == b)
			found = TRUE;
		i++;
	}
	if (found == FALSE)
	{
		t_room_list_add(b->parent, a);
		t_room_list_add(a->children, b);
	}
}

void print_room(t_room *room, size_t index)
{
	size_t j;

	ft_printf("[%7u] - {%3s} - {%9s} - {%9s} - [%4lld] {", index, room->name,
		status_str(room->status),
		(room->occuped == TRUE ? "occuped" : "empty"),
		room->distance);
	j = 0;
	while (j < room->parent->size)
	{
		if (j != 0)
			ft_printf(" ");
		ft_printf("{%s / %u}", t_room_list_at(room->parent, j)->name, t_room_list_at(room->parent, j)->distance);
		j++;
	}
	ft_printf("}\n");
}
