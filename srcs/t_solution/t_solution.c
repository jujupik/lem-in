/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_solution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:51 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 16:51:07 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_solution	create_solution(void)
{
	t_solution	result;

	result.paths = create_path_list(50);
	result.note = FLT_MAX;
	return (result);
}

void		destroy_solution(t_solution to_destroy)
{
	destroy_path_list(to_destroy.paths);
}

void		add_path_to_solution(t_solution *solution, t_path to_add)
{
	t_path_list_add(&(solution->paths), to_add);
}

void		clear_solution(t_solution *solution)
{
	solution->paths.size = 0;
	solution->note = FLT_MAX;
}
