#include "lem_in.h"

void	calc_complete_distance(t_room *room, size_t parent_dist)
{
	t_link *link;
	t_room *next;
	size_t i;

	room->distance = parent_dist;
	if (room->state == end)
		return ;
	i = 0;
	while (i < room->links->size)
	{
		link = list_at(room->links, i);
		next = (link->children != room ? link->children : link->parent);
		if (next->state != end && next->distance > room->distance)
				calc_complete_distance(next, parent_dist + 1);
		else if (next->state == end && (next->distance == UINT_MAX ||
				next->distance < room->distance))
				calc_complete_distance(next, parent_dist + 1);
		i++;
	}
}

BOOL add_room_to_list(t_list *list, t_room *room, t_room *next)
{
	if (next->distance > room->distance)
	{
		next->previous = room;
		next->distance = room->distance + 1;
		list_push_back(list, next);
		if (next->state == end)
			return (TRUE);
	}
	return (FALSE);
}

BOOL add_room_to_calc(t_list *list, t_room *room)
{
	size_t i;
	t_link *link;
	t_room *next;

	i = 0;
	while (i < room->links->size)
	{
		link = list_at(room->links, i);
		next = (link->children != room ? link->children : link->parent);
		if (next != room->previous && next->state != start)
		{
			if ((link->flow == 0 && room_flow_children(room) == 0 && next->active == FALSE) || room->state == start)
			{
				if (add_room_to_list(list, room, next) == TRUE)
					return (TRUE);
			}
			else if (link->flow < 0 && next == link->parent && next->previous != room)
			{
				if (add_room_to_list(list, room, next) == TRUE)
					return (TRUE);
			}
			else if (link->flow < 0 && link->parent == room)
			{
				if (add_room_to_list(list, room, next) == TRUE)
					return (TRUE);
			}
			else
			{
				link = search_link(room, room->previous);
				if (room_flow_parent(next) == 0 && link->parent == room)
				{
					if (add_room_to_list(list, room, next) == TRUE)
						return (TRUE);
				}
			}
		}
		i++;
	}
	return (FALSE);
}

void calc_distance(t_room *room, size_t parent_dist)
{
	t_room *tmp_room;
	size_t i;
	size_t j;
	t_list list;

	list = create_list(500);
	list_push_back(&list, room);
	room->distance = 0;
	i = 0;
	while (i < list.size)
	{
		tmp_room = list_at(&list, i);
		if (add_room_to_calc(&list, tmp_room) == TRUE)
			return ;
		i++;
	}
}
