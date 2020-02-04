#include "lem_in.h"

void	set_map_room(t_map *map, t_room *room)
{
	if (room->state == start)
	{
		if (map->start != NULL)
			map->start->state = normal;
		map->start = room;
	}
	else if (room->state == end)
	{
		if (map->end != NULL)
			map->end->state = normal;
		map->end = room;
	}
}

void	add_room(t_map *map, char *line, t_room_state *state)
{
	char **tab;
	t_room *room;

	tab = ft_strsplit(line, ' ');
	room = malloc_room(tab[0], *state, ft_atoi(tab[1]), ft_atoi(tab[2]));
	list_push_back(map->room_list, room);
	set_map_room(map, room);
	*state = normal;
	ft_tab_free(tab);
}

t_room	*search_room(t_map *map, char *room_name)
{
	t_room	*room;
	size_t	i;

	i = 0;
	while (i < map->room_list->size)
	{
		room = list_at(map->room_list, i);
		if (ft_strcmp(room->name, room_name) == 0)
			return (room);
		i++;
	}
	return (NULL);
}
