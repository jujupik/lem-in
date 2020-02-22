/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/22 18:15:07 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	solution_note(t_list *paths)
{
	t_path	*tmp;

	tmp = get_longuest_path(paths);
	if (tmp == NULL)
		return (0);
	return (tmp->road->size + tmp->count);
}

t_path	*get_path(t_room *room)
{
	t_path	*path;

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

t_list	*parse_path(t_map *map)
{
	t_list	*result;
	t_list	*tmp;
	t_path	*path;
	t_room	*room;
	size_t	i;

	i = 0;
	result = NULL;
	while (i < map->start->links->size)
	{
		reset_distance(map);
		calc_distance(map->start, 0);
		path = get_path(map->end);
		if (path != NULL)
			active_path(path);
		tmp = find_all_path(map);
		prepare_path(map, tmp);
		if (result == NULL || solution_note(tmp) < solution_note(result))
			result = tmp;
		else
			return (result);
		i++;
	}
	return (result);
}

int		main(void)
{
	t_map	map;
	t_list	*paths;
	t_path	*tmp;

	map = parse_map();
	paths = parse_path(&map);
	tmp = get_longuest_path(paths);
	if (tmp != NULL)
		ft_printf("\nfor %u ants -> Nb turn : %u\n", map.nb_fourmis, tmp->road->size + tmp->count - 2);
	return (0);
}
