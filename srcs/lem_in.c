/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/26 19:30:41 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_map_output(t_map *map)
{
	size_t i;

	i = 0;
	while (i < map->map_string->size)
	{
		ft_printf("%s\n", list_at(map->map_string, i));
		i++;
	}
}

void		print_path_output(t_map *map, t_list *paths)
{
	t_path	*tmp;
	t_room	*room;
	size_t	note;
	size_t	index[2];

	index[0] = 0;
	while (index[0] < paths->size)
	{
		tmp = list_at(paths, index[0]);
		if (index[0] != 0)
			ft_printf("\n");
		ft_printf("Path %u : len %u / Nb fourmi %u\n", index[0],
		tmp->road->size, tmp->count);
		index[1] = 0;
		while (index[1] < tmp->road->size)
		{
			room = list_at(tmp->road, index[1]);
			ft_printf("%s[%4s]", (index[1] != 0 ? " - " : ""), room->name);
			index[1]++;
		}
		ft_printf("\n");
		index[0]++;
	}
	note = solution_note(paths);
	ft_printf("\nfor %u ants -> Nb turn : %u\n", map->nb_fourmis, note);
}

void		lem_in_printer(t_map *map, t_list *paths, BOOL *options)
{
	if (options[VERBOSE] == TRUE)
		ft_printf("Paths parsing done !\n\n");
	if (options[SIMPLE] == FALSE)
		print_ant_output(map, paths, options[0]);
	if (options[MAP] == TRUE || options[MAP_ACTIVE] == TRUE)
	{
		if (options[MAP_ACTIVE] == TRUE)
			print_active_map(map);
		else
			print_map(map);
	}
	if (options[VERBOSE] == TRUE || options[SIMPLE] == TRUE)
	{
		ft_printf("\n");
		print_path_output(map, paths);
	}
}

static void lem_in_checker(t_map *map, t_list *paths)
{
	(void)map;
	(void)paths;
	ft_printf("TO DO : Lem-in checker\n");
}

void		lem_in(BOOL *options)
{
	t_map	map;
	t_list	*paths;

	map = parse_map();
	print_map_output(&map);
	ft_printf("\n");
	paths = parse_path(&map);
	if (paths != NULL && paths->size != 0 && map.nb_fourmis > 0)
		lem_in_printer(&map, paths, options);
	else if (map.nb_fourmis <= 0)
		ft_printf("No ant to move\n");
	else
		ft_printf("No path found\n");
	if (paths != NULL)
		free_list(paths, tmp_free_path);
	lem_in_checker(&map, paths);
	destroy_map(map);
}
