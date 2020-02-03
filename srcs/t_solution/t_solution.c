/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_solution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:51 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 08:00:07 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_solution	create_solution(void)
{
	t_solution	result;

	result.paths = create_path_list(50);
	result.note = UINT_MAX;
	return (result);
}

t_solution	*malloc_solution(void)
{
	t_solution	*result;

	result = (t_solution *)malloc(sizeof(t_solution));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_solution");
	*result = create_solution();
	return (result);
}

void		destroy_solution(t_solution to_destroy)
{
	destroy_path_list(to_destroy.paths);
}

void		add_path_to_solution(t_solution *solution, t_path *to_add)
{
	t_path_list_add(&(solution->paths), to_add);
}

void		clear_solution(t_solution *solution)
{
	solution->paths.size = 0;
	solution->note = UINT_MAX;
}

void		clear_solution_index(t_solution *solution, size_t index)
{
	solution->paths.size = index;
	solution->note = UINT_MAX;
}
