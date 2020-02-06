#include "lem_in.h"

t_path	*calc_path(t_map *map)
{
	(void)map;
	return (NULL);
}

t_room *get_next_room(t_room *room)
{
	t_link *link;
	t_room *next;
	size_t i;

	i = 0;
	while (i < room->links->size)
	{
		link = list_at(room->links, i);
		next = (link->children != room ? link->children : link->parent);
		if (next->distance == room->distance - 1)
			return (next);
		i++;
	}
	return (NULL);
}

t_path *get_path(t_room *room)
{
	t_path *path;

	path = malloc_path(500);
	while (room != NULL && room->state != start)
	{
		add_room_to_path(path, room);
		room = get_next_room(room);
	}
	if (room == NULL)
	{
		free_path(path);
		return (NULL);
	}
	add_room_to_path(path, room);
	reverse_path(path);
	return (path);
}

t_list parse_path(t_map *map)
{
	t_list result;

	result = create_list(500);
	(void)map;
	return (result);
}

t_path *get_shorter_path(t_list *paths)
{
	t_path	*tmp;
	t_path	*result;
	size_t	i;

	i = 0;
	result = NULL;
	while (i < paths->size)
	{
		tmp = list_at(paths, i);
		if (result == NULL || result->road->size + result->count > tmp->road->size + tmp->count)
			result = tmp;
		i++;
	}
	return (result);
}

t_path *get_longuest_path(t_list *paths)
{
	t_path	*tmp;
	t_path	*result;
	size_t	i;

	i = 0;
	result = NULL;
	while (i < paths->size)
	{
		tmp = list_at(paths, i);
		if ((result == NULL || result->road->size + result->count < tmp->road->size + tmp->count) && tmp->count != 0)
			result = tmp;
		i++;
	}
	return (result);
}

void prepare_path(t_map *map, t_list *paths)
{
	size_t i;
	t_path *tmp_path;

	i = 0;
	while (i < paths->size)
	{
		tmp_path = list_at(paths, i);
		tmp_path->count = 0;
		i++;
	}
	i = 0;
	while (i < map->nb_fourmis)
	{
		tmp_path = get_shorter_path(paths);
		if (tmp_path != NULL)
			tmp_path->count++;
		i++;
	}
}

void	active_path(t_path *path)
{
	t_link *link;
	t_room *room;
	t_room *next;
	size_t i;

	i = 0;
	while (i < path->road->size - 1)
	{
		room = list_at(path->road, i);
		next = list_at(path->road, i + 1);
		link = search_link(room, next);
		if (next->state == normal)
			next->active = TRUE;
		if (room == link->parent)
			link->flow++;
		else
			link->flow--;
		i++;
	}
}

int main()
{
	t_map map;
	t_list paths;
	t_path *tmp;

	map = parse_map();
	for (size_t i = 0; i < 3; i++)
	{
		reset_distance(&map);
		calc_distance(map.start, 0);
		t_path *path = get_path(map.end);
		if (path != NULL)
		{
			ft_printf("\n\n");
			print_path(path);
			active_path(path);
		}
		//ft_printf("\n\n");
		//print_map(&map);

	}
	ft_printf("\n\n");
	print_map(&map);

	// exit(0);
	// paths = parse_path(&map);
	return (0);
}
