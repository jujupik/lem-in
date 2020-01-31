/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:46 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 20:30:51 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void				calc_next_valid_path(t_map *map, t_ptr_room to_test,
							t_solution *solution)
{
	t_path	path;

	calc_distance(map);
	if (to_test->occuped == FALSE)
	{
		to_test->occuped = TRUE;
		path = calc_path(map, to_test);
		if (path.size != 0)
		{
			add_path_to_solution(solution, path);
		}
	}
}

static t_intstr_list	calc_value_list(t_map *map)
{
	t_intstr_list	value_list;

	value_list = create_intstr_list(map->end->links->size);
	generate_solution_value(&value_list, 0, map->end->links->size);
	return (value_list);
}

void					calc_solution(t_map *map, t_intstr_list *value_list,
							size_t index, t_solution *solution)
{
	size_t		j;
	t_int_array	list_array;

	list_array = t_intstr_list_at(value_list, index);
	j = 0;
	while (j < list_array.size)
	{
		calc_next_valid_path(map, t_ptr_room_list_at(map->end->links,
			list_array.content[j]), solution);
		j++;
	}
	calc_solution_note(solution);
}

void					solver(t_map *map)
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
	print_solution(&saved_solution);
}
