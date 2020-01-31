/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:46 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 22:58:38 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_solution		single_path_solver(t_path path)
{
	t_solution		solution;


	solution = create_solution();
	add_path_to_solution(&solution, path);
	return (solution);
}

static t_solution		multi_path_solver(t_map *map)
{
	size_t			i;
	t_solution		solution;
	t_solution		saved_solution;
	t_intstr_list	value_list;

	solution = create_solution();
	saved_solution = create_solution();
	value_list = calc_value_list(map);
	i = 0;
	while (i < value_list.size)
	{
		calc_solution(map, &value_list, i, &solution);
		if (saved_solution.note > solution.note)
			copy_solution(&saved_solution, &solution);
		clear_solution(&solution);
		reset_map_occupation(map);
		i++;
	}
	reverse_solution(&saved_solution);
	return (saved_solution);
}

t_solution				solver(t_map *map)
{
	t_path mono_path;
	t_solution solution;

	calc_distance(map);
	mono_path = calc_path(map, map->end);
	if (mono_path.size >= (size_t)(map->nb_fourmis))
	{
		solution = single_path_solver(mono_path);
		reverse_solution(&solution);
		return (solution);
	}
	else
	{
		destroy_ptr_room_list(mono_path);
		solution = multi_path_solver(map);
		return (solution);
	}
}
