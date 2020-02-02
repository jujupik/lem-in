/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_solution_note.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:49 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/02 20:48:32 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path *get_shorter_path(t_solution *solution)
{
	t_path *tmp;
	t_path *result;
	size_t i;

	i = 0;
	result = NULL;
	while (solution->paths.size > i )
	{
		tmp = t_path_list_at(&(solution->paths), i);
		if (result == NULL || tmp->path->size + tmp->count <
			result->path->size + result->count)
			result = tmp;
		i++;
	}
	return (result);
}

t_path *get_longest_path(t_solution *solution)
{
	t_path *tmp;
	t_path *result;
	size_t i;

	i = 0;
	result = NULL;
	while (i < solution->paths.size)
	{
		tmp = t_path_list_at(&(solution->paths), i);
		if (result == NULL || (tmp->path->size + tmp->count >
			result->path->size + result->count &&
			tmp->count != 0))
			result = tmp;
		i++;
	}
	return (result);
}

void place_fourmis(t_map *map, t_solution *solution)
{
	t_path *tmp;
	size_t	i;

	i = 0;
	while (i < map->nb_fourmis)
	{
		tmp = get_shorter_path(solution);
		if (tmp != NULL)
			tmp->count++;
		i++;
	}
}

void	calc_solution_note(t_map *map, t_solution *solution)
{
	t_path *tmp;

	if (solution->paths.size == 0)
	{
		solution->note = UINT_MAX;
		return ;
	}

	place_fourmis(map, solution);
	tmp = get_longest_path(solution);
	solution->note = tmp->path->size + tmp->count;
}
