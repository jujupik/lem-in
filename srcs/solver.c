/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:46 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/02 21:50:03 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_solution		single_path_solver(t_map *map, t_path *path)
{
	t_solution		solution;

	solution = create_solution();
	add_path_to_solution(&solution, path);
	calc_solution_note(map, &solution);
	return (solution);
}

BOOL			check_availible_path(t_map *map, t_path **result, t_room *departure)
{
	t_path_list list_paths;
	t_path *tmp;
	int index;
	int i;

	index = -1;
	i = 0;
	while (i < (int)(map->end->links->size))
	{
		if (departure == t_ptr_room_list_at(map->end->links, i))
			index = i;
		i++;
	}
	if (index == -1)
		return (FALSE);
	list_paths = g_saved_path[index];
	i = 0;
	while (i < (int)(list_paths.size))
	{
		tmp = t_path_list_at(&list_paths, i);
		if (t_ptr_room_list_at(tmp->path, tmp->path->size - 1)->occuped == FALSE)
		{
			*result = tmp;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void				calc_next_valid_path(t_map *map, t_ptr_room to_test,
							t_solution *solution)
{
	t_path	*path;

	calc_distance(map);
	if (to_test->occuped == FALSE)
	{
		// if (check_availible_path(map, &path, to_test) == TRUE)
		// 	add_path_to_solution(solution, path);
		// else
		// {
			to_test->occuped = TRUE;
			path = calc_path(map, to_test);
			if (path != NULL)
				add_path_to_solution(solution, path);
		// }
	}
}

t_solution		*calc_solution(t_map *map, int *value_list)
{
	static t_solution *solution = NULL;
	size_t		j;

	j = 0;
	while (j < map->end->links->size)
	{
		if (j != 0)
			ft_printf(" - ");
		ft_printf("%d", value_list[j]);
		j++;
	}
	ft_printf("\n");
	if (solution == NULL)
		solution = malloc_solution();
	clear_solution(solution);
	j = 0;
	while (j < map->end->links->size)
	{
		calc_next_valid_path(map, t_ptr_room_list_at(map->end->links,
			value_list[j]), solution);
		j++;
	}
	calc_solution_note(map, solution);
	reset_map_occupation(map);
	return (solution);
}

static int	*create_value_list(int nb_value)
{
	int	*value;
	int	j;

	value = ft_int_str_new(nb_value);
	j = 0;
	while (j < nb_value)
	{
		value[j] = j;
		j++;
	}
	return (value);
}

void	generate_optimial_solution(t_map *map, t_solution *result, int len, int nb_value)
{
	t_solution	*tmp;
	static int	*value_list = NULL;
	int			i;

	if (value_list == NULL)
		value_list = create_value_list(nb_value);
	if (len == nb_value)
	{
		tmp = calc_solution(map, value_list);
		if (tmp->note < result->note)
			copy_solution(result, tmp);
	}
	else
	{
		i = len;
		while (i < nb_value)
		{
			ft_swap_int(&(value_list[len]), &(value_list[i]));
			generate_optimial_solution(map, result, len + 1, nb_value);
			ft_swap_int(&(value_list[len]), &(value_list[i]));
			i++;
		}
	}
}

void		multi_path_solver(t_map *map, t_solution *saved_solution)
{
	calc_distance(map);
	generate_optimial_solution(map, saved_solution, 0, map->end->links->size);
	reverse_solution(saved_solution);
}

t_solution				solver(t_map *map)
{
	t_solution	solution;

	calc_distance(map);
	solution = single_path_solver(map, calc_path(map, map->end));
	multi_path_solver(map, &solution);
	return (solution);
}
