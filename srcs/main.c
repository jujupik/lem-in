/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/22 19:50:59 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void print_map_output(t_map *map)
{
	size_t i;

	i = 0;
	while (i < map->map_string->size)
	{
		ft_printf("%s\n", list_at(map->map_string, i));
		i++;
	}
}

void print_path_output(t_map *map, t_list *paths)
{
	t_path	*tmp;

	for (size_t i = 0; i < paths->size; i++)
	{
		tmp = list_at(paths, i);
		for (size_t j = 0; j < tmp->road->size; j++)
			ft_printf("%s%s", (j != 0 ? " - " : ""), ((t_room *)(list_at(tmp->road, j)))->name);
		ft_printf("\n");
	}
	tmp = get_longuest_path(paths);
	if (tmp != NULL)
		ft_printf("for %u ants -> Nb turn : %u\n", map->nb_fourmis, tmp->road->size + tmp->count - 2);
}

int		main(void)
{
	t_map	map;
	t_list	*paths;

	map = parse_map();
	paths = parse_path(&map);
	print_map_output(&map);
	ft_printf("\n");
	print_path_output(&map, paths);
	return (0);
}
