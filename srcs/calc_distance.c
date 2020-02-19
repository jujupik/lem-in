#include "lem_in.h"

void calc_distance(t_room *room, size_t parent_dist)
{
	t_room *tmp_room;
	t_link *tmp_link;
	size_t i;
	size_t j;
	t_list list;

	list = create_list(500);
	list_push_back(&list, room);
	room->distance = 0;
	i = 0;
	while (i < list.size)
	{
		room = list_at(&list, i);
		j = 0;
		while (room->state != end && j < room->links->size)
		{
			tmp_link = list_at(room->links, j);
			if (tmp_link->actual_parent == NULL || tmp_link->flow == 0)
			{
				tmp_room = (tmp_link->children == room ? tmp_link->parent : tmp_link->children);
				if (tmp_room->distance > room->distance + 1)
				{
					tmp_room->distance = room->distance + 1;
					tmp_link->actual_parent = room;
					list_push_back(&list, tmp_room);
				}
			}
			else if (tmp_link->actual_parent != room && tmp_link->flow == 1)
			{
				tmp_room = (tmp_link->children == room ? tmp_link->parent : tmp_link->children);
				if (tmp_room->distance > room->distance + 1)
				{
					tmp_room->distance = room->distance + 1;
					list_push_back(&list, tmp_room);
				}
			}
			j++;
		}
		i++;
	}
}
