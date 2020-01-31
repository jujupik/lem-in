/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:46 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/01 00:09:38 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_solution		single_path_solver(t_path path)
{
	t_solution		solution;

	solution = create_solution();
	add_path_to_solution(&solution, path);
	return (solution);
}

void		multi_path_solver(t_map *map, t_solution *saved_solution)
{
	size_t			i;
	t_solution		solution;
	t_intstr_list	value_list;

	solution = create_solution();
	calc_distance(map);
	value_list = calc_value_list(map);
	i = 0;
	while (i < value_list.size)
	{
		calc_solution(map, &value_list, i, &solution);
		if (saved_solution->note > solution.note)
			copy_solution(saved_solution, &solution);
		clear_solution(&solution);
		reset_map_occupation(map);
		i++;
	}
	reverse_solution(saved_solution);
}

t_solution				solver(t_map *map)
{
	t_path path;
	t_solution solution;

	calc_distance(map);
	path = calc_path(map, map->end);
	solution = single_path_solver(path);
	calc_solution_note(map, &solution);
	multi_path_solver(map, &solution);
	return (solution);
}
