/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:09:50 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 14:09:52 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void reset_map_occupation(t_map *map)
{
	t_room *room;

	for (size_t i = 0; i < map->room_list->size; i++)
	{
		room = t_room_list_get(map->room_list, i);
		room->occuped = FALSE;
	}

}

void solver(t_map *map)
{
	t_ptr_room_list list;
	t_intstr_list value_list;
	t_int_array list_array;
	t_ptr_room	to_test;
	t_path path;

	list = create_ptr_room_list(50);
	for (size_t i = 0; i < map->end->links->size; i++)
		t_ptr_room_list_add(&list, t_ptr_room_list_at(map->end->links, i));
	value_list = create_intstr_list(list.size);
	generate_solution_value(&value_list, 0, list.size);
	for (size_t i = 0; i < value_list.size; i++)
	{
		list_array = t_intstr_list_at(&value_list, i);
		calc_distance(map);
		ft_printf("Solution [%u] - \n", i);
		for (size_t j = 0; j < list_array.size; j++)
		{
			to_test = t_ptr_room_list_at(&list, list_array.content[j]);
			if (to_test->occuped == FALSE)
			{
				to_test->occuped = TRUE;
				path = calc_path(map, to_test);
				print_path(&path, to_test->name);
			}
			else
				print_path(NULL, to_test->name);
		}
		ft_printf("\n\n\n");
		reset_map_occupation(map);
	}
}

int	main(void)
{
	t_map map;

	map = create_map();
	parse_map(&map);
	solver(&map);
	return (0);
}
