/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_solution.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:55:14 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 07:41:25 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_SOLUTION_H
# define LEM_IN_SOLUTION_H

typedef struct		s_solution
{
	t_path_list		paths;
	size_t			note;
}					t_solution;

t_solution			create_solution();
t_solution			*malloc_solution();
void				destroy_solution(t_solution to_destroy);
void				add_path_to_solution(t_solution *solution, t_path *to_add);
void				clear_solution(t_solution *solution);
void				clear_solution_index(t_solution *solution, size_t index);
void				print_solution(t_solution *solution);
void				calc_solution_note(t_map *map, t_solution *solution);
void				copy_solution(t_solution *dest, t_solution *src);
void				reverse_solution(t_solution *solution);
t_solution			*calc_solution(t_map *map, int *value_list, int index);
void				calc_next_valid_path(t_map *map, t_solution *solution, size_t index);
t_intstr_list		calc_value_list(t_map *map);

#endif
