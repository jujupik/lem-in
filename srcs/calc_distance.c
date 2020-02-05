#include "lem_in.h"

void	calc_distance(t_room *room, size_t parent_dist);
t_path	*calc_path(t_map *map);
t_room	*get_next_room(t_room *room);
t_path	*get_path(t_room *room);
t_list	parse_path(t_map *map);
t_path	*get_shorter_path(t_list *paths);
t_path	*get_longuest_path(t_list *paths);
void	prepare_path(t_map *map, t_list *paths);

void	calc_distance(t_room *room, size_t parent_dist)
{
	t_link *tmp_link;
	t_room *tmp_room;
	size_t i;

	if (room == NULL)
		return ;

	ft_printf("Set distance of %s from %u -> %u\n", room->parent_dist)
	room->distance = parent_dist;
	if (room->state == end)
		return ;
	i = 0;
	while (i < room->links->size)
	{
		tmp_link = list_at(room->links, i);
		tmp_room = tmp_link->children;
		if (tmp_room == room)
			tmp_room = tmp_link->parent;
		if (ft_strcmp(room->name, "Omd6") == 0 || ft_strcmp(tmp_room->name, "Omd6") == 0)
			ft_printf("Test for %u > %u && %d == 0 && (room->active == %b || (room->active == %b && room->previous->active == %b && tmp_room->active == %b))\n", tmp_room->distance, parent_dist, tmp_link->flow, room->active, room->active, room->previous->active, tmp_room->active);
		if (tmp_room->distance > parent_dist && tmp_link->flow == 0 && (room->active == FALSE || (room->active == TRUE && room->previous->active == TRUE && tmp_room->active == FALSE)))
		{
			if (ft_strcmp(room->name, "Omd6") == 0)
				ft_printf("Entry 1\n");
			if (ft_strcmp(tmp_room->name, "Omd6") == 0)
				ft_printf("Entry 2\n");
			tmp_room->previous = room;
			calc_distance(tmp_room, parent_dist + 1);
		}
		if (tmp_room->distance > parent_dist && tmp_link->flow == 1 && room->active == TRUE && tmp_room->active == TRUE)
		{
			if (ft_strcmp(room->name, "Omd6") == 0)
				ft_printf("Entry 3\n");
			if (ft_strcmp(tmp_room->name, "Omd6") == 0)
				ft_printf("Entry 4\n");
			tmp_room->previous = room;
			calc_distance(tmp_room, parent_dist + 1);
		}
		i++;
	}
}
