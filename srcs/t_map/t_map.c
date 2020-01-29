#include "lem_in.h"

t_map create_map()
{
	t_map result;

	result.nb_fourmis = 0;
	result.room_list = malloc_room_list(500);
	result.start = NULL;
	result.end = NULL;
	return (result);
}

t_map *malloc_map()
{
	t_map	*result;

	result = (t_map *)malloc(sizeof(t_map));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_map");
	*result = create_map();
	return (result);
}

void destroy_map(t_map to_destroy) // On detruit via les fonctions de free tout ce qui est DANS la structure
{
	free_room_list(to_destroy.room_list);
}

void free_map(t_map *to_free) // On free la structure en elle meme
{
	destroy_map(*to_free);
	free(to_free);
}

void print_map(t_map *map)
{
	ft_printf("nb fourmis : %d\n\n", map->nb_fourmis);
	ft_printf("start room : %s\n", (map->start == NULL ? "(null)" : map->start->name));
	ft_printf("end room : %s\n\n", (map->end == NULL ? "(null)" : map->end->name));
	for (size_t i = 0; i < map->room_list->size; i++)
	{
		t_room *room;

		room = t_room_list_get(map->room_list, i);
		ft_printf("[%u] - {%s}\n", i , room->name);
		if (room->links->size == 0)
			ft_printf("	Links : (NO LINKS)\n");
		else
		{
			ft_printf("	Links : ");
			for (size_t j = 0; j < room->links->size; j++)
			{
				if (j != 0)
					ft_printf(" - ");
				ft_printf("(%s)", t_ptr_room_list_at(room->links, j)->name);
			}
			ft_printf("\n");
		}
	}
}
