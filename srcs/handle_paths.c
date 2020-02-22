/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:10:44 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/22 18:12:25 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*retrieve_path(t_room *start, t_room *room)
{
	t_path	*path;

	path = malloc_path();
	add_room_to_path(path, start);
	add_room_to_path(path, room);
	while (room != NULL && room->state != end)
	{
		room = find_next_room(room);
		add_room_to_path(path, room);
	}
	if (room == NULL || room->state != end)
	{
		free_path(path);
		return (NULL);
	}
	return (path);
}

t_list	*find_all_path(t_map *map)
{
	t_list	*result;
	t_path	*path;
	t_room	*room;
	size_t	i;

	i = 0;
	result = malloc_list(500);
	while (i < map->start->links->size)
	{
		room = ((t_link *)list_at(map->start->links, i))->children;
		path = retrieve_path(map->start, room);
		if (path != NULL)
			list_push_back(result, path);
		i++;
	}
	return (result);
}

void	prepare_path(t_map *map, t_list *paths)
{
	size_t	i;
	t_path	*tmp_path;

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
	t_link	*link;
	t_room	*room;
	t_room	*next;
	size_t	i;

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
