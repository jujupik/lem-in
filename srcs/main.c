/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 15:37:13 by jrouchon         ###   ########.fr       */
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

static void	lem_in(BOOL verbose)
{
	t_map	map;
	t_list	*paths;

	map = parse_map();
	paths = parse_path(&map);
	print_map_output(&map);
	ft_printf("\n");
	if (paths->size != 0)
	{
		print_ant_output(&map, paths, verbose);
		if (verbose == TRUE)
		{
			ft_printf("\n");
			print_path_output(&map, paths);
		}
	}
	else
		ft_printf("No path found\n");
	free_list(paths, tmp_free_path);
	destroy_map(map);
}

int			main(int argc, char **argv)
{
	BOOL	verbose;

	verbose = FALSE;
	if (argc >= 2)
	{
		if (argc == 2 && (ft_strcmp(argv[1], "--v") == TRUE ||
			ft_strcmp(argv[1], "-v") == TRUE))
			verbose = TRUE;
		else
		{
			ft_printf("Format : ./lem-in --v < [Map a tester]\n");
			return (0);
		}
	}
	lem_in(verbose);
	return (0);
}
