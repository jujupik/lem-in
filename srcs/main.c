#include "lem_in.h"

void calc_distance(t_room *room, size_t parent_dist);
t_path	*calc_path(t_map *map);
t_room *get_next_room(t_room *room);
t_path *get_path(t_room *room);
t_list parse_path(t_map *map);
t_path *get_shorter_path(t_list *paths);
t_path *get_longuest_path(t_list *paths);
void prepare_path(t_map *map, t_list *paths);

t_path	*calc_path(t_map *map)
{
	t_room	*tmp_room;
	t_room	*actual;
	t_path	*result;

	result = malloc_path(500);
	reset_distance(map);
	calc_distance(map->start, 0);
	actual = map->end;
	while (actual != NULL)
	{
		//if (actual->state != start)
		add_room_to_path(result, actual);
		actual = actual->previous;
	}
	if (result->road->size == 1)
		return (NULL);
	return (result);
}

t_room *get_next_room(t_room *room)
{
	t_link *tmp_link;
	size_t i;

	i = 0;
	while (i < room->children->size)
	{
		tmp_link = list_at(room->children, i);
		if (tmp_link->flow == 1)
			return (tmp_link->children);
		i++;
	}
	return (NULL);
}

t_path *get_path(t_room *room)
{
	t_path *result;

	result = malloc_path();
	while (room != NULL)
	{
		add_room_to_path(result, room);
		room = get_next_room(room);
	}
	if (result->road->size == 1)
		return (NULL);
	return (result);
}

t_list parse_path(t_map *map)
{
	t_path *path;
	size_t i;
	t_list paths;
	t_link *tmp_link;

	paths = create_list(map->end->parent->size);
	i = 0;
	path = (void *)1;
	while (i < map->start->children->size && path != NULL)
	{
		path = calc_path(map);
		if (path != NULL)
		{
			prepare_path(map, &paths);
			if (paths.size == 0 || path->road->size < get_longuest_path(&paths)->road->size + get_longuest_path(&paths)->count)
			{
				reverse_path(path);
				active_path(path);
				list_push_back(&paths, path);
			}
		}
		i++;
	}
	return (paths);
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

int main()
{
	t_map map;
	t_list paths;
	t_path *tmp;

	map = parse_map();
	paths = parse_path(&map);
	prepare_path(&map, &paths);
	for (size_t i = 0; i < paths.size; i++)
	{
		t_path *tmp = list_at(&paths, i);
		if (tmp->count != 0)
			print_path(tmp);
	}
	print_map(&map);
	size_t i = 0;
	tmp = NULL;
	while (tmp == NULL || tmp->count == 0)
	{
		tmp = list_at(&paths, i);
		i++;
	}
	ft_printf("\nfor %u ants -> Nb turn : %u\n", map.nb_fourmis, tmp->road->size + tmp->count - 2);
	return (0);
}
