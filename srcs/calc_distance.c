#include "lem_in.h"

void calc_distance(t_room *room, size_t parent_dist);
t_path	*calc_path(t_map *map);
t_room *get_next_room(t_room *room);
t_path *get_path(t_room *room);
t_list parse_path(t_map *map);
t_path *get_shorter_path(t_list *paths);
t_path *get_longuest_path(t_list *paths);
void prepare_path(t_map *map, t_list *paths);

// void calc_distance_parent(t_room *room, size_t parent_dist)
// {
// 	t_link *tmp_link;
// 	t_room *tmp_room;
// 	size_t i;
//
//
// }
// void calc_distance_enfant(t_room *room, size_t parent_dist)
// {
//
//
// }

// void calc_distance(t_room *room, size_t parent_dist)
// {
// 	t_link *tmp_link;
// 	t_room *tmp_room;
// 	size_t i;
//
// 	room->distance = parent_dist;
// 	i = 0;
// 	while (i < room->parent->size && room->active == TRUE)
// 	{
// 		tmp_link = list_at(room->parent, i);
// 		tmp_room = tmp_link->parent;
// 		if (tmp_room->distance > parent_dist && tmp_link->flow == 1)
// 		{
// 			tmp_room->previous = room;
// 			calc_distance(tmp_room, parent_dist + 1);
// 		}
// 		i++;
// 	}
// 	while (i < room->children->size && (room->previous == NULL || room->active == FALSE || (room->previous->active == TRUE && room->active == TRUE)))
// 	{
// 		tmp_link = list_at(room->children, i);
// 		tmp_room = tmp_link->children;
// 		if (tmp_room->distance > parent_dist && tmp_link->flow == 0)
// 		{
// 			tmp_room->previous = room;
// 			calc_distance(tmp_room, parent_dist + 1);
// 		}
// 		i++;
// 	}
// }