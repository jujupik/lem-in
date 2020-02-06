#include "lem_in.h"

void	reset_distance(t_map *map)
{
	t_room	*tmp;
	size_t	i;

	i = 0;
	while (i < map->room_list->size)
	{
		tmp = list_at(map->room_list, i);
		tmp->distance = UINT_MAX;
		tmp->previous = NULL;
		i++;
	}
}

void	reverse_path(t_path *path)
{
	t_list		*list;
	void		*tmp;
	size_t		i;

	i = 0;
	list = path->road;
	while (i < list->size / 2)
	{
		tmp = list_at(list, i);
		*(list_get(list, i)) = list_at(list, list->size - 1 - i);
		*(list_get(list, list->size - 1 - i)) = tmp;
		i++;
	}
}

t_link	*search_link(t_room *actual, t_room *dest)
{
	size_t	i;
	t_link	*link;

	link = NULL;
	i = 0;
	while (i < actual->links->size)
	{
		link = list_at(actual->links, i);
		if (ft_strcmp(link->children->name, dest->name) == 0 ||
			ft_strcmp(link->parent->name, dest->name) == 0)
			return (link);
		i++;
	}
	return (NULL);
}
