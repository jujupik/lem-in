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

// typedef struct s_solution
// {
// 	t_path_list *paths;
// }				t_solution;

// t_solution create_solution()
// {
//
// }
//
// t_solution *malloc_solution()
// {
//
// }
//
// void destroy_solution(t_solution to_destroy)
// {
//
// 	free_path_list(to_destroy.paths);
// }
//
// void free_solution(t_solution *to_free)
// {
// 	destroy_solution(*to_free);
// 	free(to_free);
// }

int	main(void)
{
	t_map map;
	t_ptr_room_list path;

	map = create_map();
	parse_map(&map);
	calc_distance(&map);
	print_map(&map);
	path = calc_path(&map, map.end);
	print_path(&path, "Path");
	return (0);
}
