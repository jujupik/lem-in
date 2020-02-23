/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:10:10 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 22:23:06 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static BOOL	is_okay_children(t_link *tmp_link, t_room *room)
{
	if (tmp_link->flow == 0 && (room->active == FALSE ||
		room->active == room->previous->active))
		return (TRUE);
	return (FALSE);
}

static BOOL	is_okay_parent(t_link *tmp_link, t_room *room, t_room *tmp_room)
{
	if (tmp_link->actual_parent != room && tmp_link->flow == 1 &&
		room->active == TRUE && tmp_room->active == TRUE)
		return (TRUE);
	return (FALSE);
}

static void	utils_calc_distance(t_list *list, t_room *tmp_room,
								t_room *room, t_link *tmp_link)
{
	if (tmp_room->distance > room->distance + 1)
	{
		tmp_room->previous = room;
		if (tmp_link->flow == 0)
			tmp_link->actual_parent = room;
		tmp_room->distance = room->distance + 1;
		list_push_back(list, tmp_room);
	}
}

void		reset_distance(t_map *map)
{
	t_room	*tmp;
	size_t	i;

	i = 0;
	while (i < map->room_list->size)
	{
		tmp = list_at(map->room_list, i);
		tmp->distance = UINT_MAX;
		tmp->previous = NULL;
		i++;
	}
}

void		calc_distance(t_room *room)
{
	t_room *tmp_room;
	t_link *tmp_link;
	size_t index[2];
	t_list list;

	list = create_list(500);
	list_push_back(&list, room);
	room->distance = 0;
	(index[0]) = 0;
	while ((index[0]) < list.size && ((index[1]) = 0) == 0)
	{
		room = list_at(&list, (index[0]));
		while (room->state != end && (index[1]) < room->links->size)
		{
			tmp_link = list_at(room->links, (index[1]));
			tmp_room = (tmp_link->children == room ?
						tmp_link->parent : tmp_link->children);
			if (is_okay_children(tmp_link, room) == TRUE ||
				is_okay_parent(tmp_link, room, tmp_room) == TRUE)
				utils_calc_distance(&list, tmp_room, room, tmp_link);
			(index[1])++;
		}
		(index[0])++;
	}
	destroy_list(list, NULL);
}
