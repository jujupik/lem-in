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
	while (i < actual->children->size)
	{
		link = list_at(actual->children, i);
		if (ft_strcmp(link->children->name, dest->name) == 0)
			return (link);
		i++;
	}
	i = 0;
	while (i < actual->parent->size)
	{
		link = list_at(actual->parent, i);
		if (ft_strcmp(link->parent->name, dest->name) == 0)
			return (link);
		i++;
	}
	return (NULL);
}

void	active_path(t_path *path)
{
	t_list	*list;
	size_t	i;
	t_room	*actual;
	t_room	*next;
	t_link	*link;
	t_link	*link2;

	list = path->road;
	if (list->size == 0)
		return ;
	i = 0;
	while (i < list->size - 1)
	{
		actual = list_at(list, i);
		next = list_at(list, i + 1);
		link = search_link(actual, next);
		link2 = search_link(next, actual);
		if (link == NULL)
			error_exit(1, "No links here");
		link->flow = (link->flow == 0 ? 1 : 0);
		//link2->flow = link->flow;
		if (actual->state == normal)
			actual->active = TRUE;
		i++;
	}
}
