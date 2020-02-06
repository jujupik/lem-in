#include "lem_in.h"

void	calc_distance(t_room *room, size_t parent_dist)
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
		if (next != room->previous && next->state != start)
		{
			ft_printf("Try room %5s to %5s -> ", room->name, next->name);
			if ((room_flow_children(room) == 0 && next->active == FALSE) || room->state == start)
			{
				ft_printf("Room children flow = 0 && next->active == FALSE -> ");
				if (next->distance > room->distance)
				{
					ft_printf("Closer\n");
					next->previous = room;
					calc_distance(next, parent_dist + 1);
				}
				else
					ft_printf("Inacessible\n");
			}
			else if (next == link->parent && next->previous != room)
			{
				ft_printf("next == link parent et next->previous != room -> ");
				if (next->distance > room->distance)
				{
					ft_printf("Closer\n");
					next->previous = room;
					calc_distance(next, parent_dist + 1);
				}
				else
					ft_printf("Inacessible\n");
			}
			else if (room_flow_parent(room) == 0 && link->parent == room)
			{
				ft_printf("room_flow_parent(next) == 0 && link->parent == room -> ");
				if (next->distance > room->distance)
				{
					ft_printf("Closer\n");
					next->previous = room;
					calc_distance(next, parent_dist + 1);
				}
			}
			else
			{
				link = search_link(room, room->previous);
				if (room_flow_parent(next) == 0 && link->parent == room)
					if (next->distance > room->distance)
					{
						ft_printf("Closer\n");
						next->previous = room;
						calc_distance(next, parent_dist + 1);
					}
				ft_printf("Inacessible\n");
			}
		}
		i++;
	}
}
