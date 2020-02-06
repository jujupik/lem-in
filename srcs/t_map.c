#include "lem_in.h"

t_map	create_map(void)
{
	t_map result;

	result.nb_fourmis = 0;
	result.room_list = malloc_list(500);
	result.start = NULL;
	result.end = NULL;
	return (result);
}

t_map	*malloc_map(void)
{
	t_map	*result;

	result = (t_map *)malloc(sizeof(t_map));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_map");
	*result = create_map();
	return (result);
}

void	destroy_map(t_map to_destroy)
{
	(void)to_destroy;
}

void	free_map(t_map *to_free)
{
	destroy_map(*to_free);
	free(to_free);
}

void		print_map(t_map *map)
{
	t_room	*room;
	size_t	i;

	i = 0;
	while (i < map->room_list->size)
	{
		room = list_at(map->room_list, i);
		print_room(room);
		i++;
	}
	ft_printf("\n----\n");
}

void		print_map_strange(t_map *map)
{
	t_room	*room;
	size_t	i;

	i = 0;
	while (i < map->room_list->size)
	{
		room = list_at(map->room_list, i);
		if (room_flow_children(room) != 0 || room_flow_parent(room) != 0 || ft_strcmp("Vnl6", room->name) == 0)
			print_room(room);
		i++;
	}
	ft_printf("\n----\n");
}
