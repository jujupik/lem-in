/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:59:24 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/22 18:04:32 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	**tab;
	t_room	*room;

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

void	calc_complete_distance(t_room *room, size_t parent_dist)
{
	t_link *link;
	t_room *next;
	size_t i;

	room->distance = parent_dist;
	if (room->state == end)
		return ;
	i = 0;
	while (i < room->links->size)
	{
		link = list_at(room->links, i);
		next = (link->children != room ? link->children : link->parent);
		if (next->state != end && next->distance > room->distance)
			calc_complete_distance(next, parent_dist + 1);
		else if (next->state == end && (next->distance == UINT_MAX ||
				next->distance < room->distance))
			calc_complete_distance(next, parent_dist + 1);
		i++;
	}
}

void	parse_parenting(t_map *map)
{
	t_room	*room;
	t_link	*link;
	size_t	i;
	size_t	j;

	i = 0;
	calc_complete_distance(map->start, 0);
	while (i < map->room_list->size)
	{
		room = list_at(map->room_list, i);
		j = 0;
		while (j < room->links->size)
		{
			link = list_at(room->links, j);
			if (link->parent->state == end || (link->children->state != end &&
				link->parent->distance > link->children->distance))
				swap_link(link);
			j++;
		}
		i++;
	}
}
