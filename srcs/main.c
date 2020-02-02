/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:09:50 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/02 22:36:29 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int get_available_path(t_solution *solution)
{
	t_path	*path;
	t_room	*room;
	size_t	i;

	i = 0;
	while (i < solution->paths.size)
	{
		path = t_path_list_at(&(solution->paths), i);
		if (path->count != 0)
		{
			room = t_ptr_room_list_at(path->path, 1);
			if (room->fourmis == NULL)
				return (i);
		}

		i++;
	}
	return (-1);
}

void move_fourmis(t_map *map, t_solution *solution, t_fourmis *fourmis)
{
	t_path	*path;
	t_room	*actual;
	t_room	*next;

	if (fourmis->path_index == -1)
	{
		fourmis->path_index = get_available_path(solution);
		if (fourmis->path_index == -1)
			return ;
		path = t_path_list_at(&(solution->paths), fourmis->path_index);
		path->count--;
	}
	path = t_path_list_at(&(solution->paths), fourmis->path_index);
	actual = t_ptr_room_list_at(path->path, fourmis->room_index);
	actual->fourmis = NULL;
	next = t_ptr_room_list_at(path->path, fourmis->room_index + 1);
	fourmis->room_index++;
	if (next == map->end)
		fourmis->arrived = TRUE;
	else
		next->fourmis = fourmis;
}

void print_out_solution(t_map *map, t_solution *solution)
{
	t_fourmis	*fourmis_array;
	BOOL		tmp;
	size_t		i;
	size_t		j;
	int			nb_tour;

	fourmis_array = (t_fourmis *)malloc(sizeof(t_fourmis) * map->nb_fourmis);
	i = 0;
	while (i < map->nb_fourmis)
	{
		fourmis_array[i] = create_fourmis(i, -1, 0);
		i++;
	}
	nb_tour = 0;
	i = 0;
	while (i < map->nb_fourmis)
	{
		j = 0;
		tmp = FALSE;
		while (j < map->nb_fourmis)
		{
			if (fourmis_array[j].arrived == FALSE)
			{
				move_fourmis(map, solution, &(fourmis_array[j]));
				if (fourmis_array[j].path_index == -1)
					break;
				// if (tmp == TRUE)
				// 	ft_printf(" ");
				// print_fourmis(solution, &(fourmis_array[j]));
				tmp = TRUE;
				if (fourmis_array[j].arrived == TRUE)
					i++;
			}
			j++;
		}
		nb_tour++;
		// ft_printf("\n");
	}
	ft_printf("NB tour : %d\n", nb_tour);
}

int	main(void)
{
	t_map		map;
	t_solution	solution;

	map = create_map();
	parse_map(&map);
	solution = solver(&map);
	//print_out_map(&map);
	print_solution(&solution);
	print_out_solution(&map, &solution);
	return (0);
}
