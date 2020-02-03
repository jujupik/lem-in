/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:46 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 02:01:31 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path_list		**g_saved_path = NULL;

t_solution		single_path_solver(t_map *map, t_path *path)
{
	t_solution		solution;

	solution = create_solution();
	add_path_to_solution(&solution, path);
	calc_solution_note(map, &solution);
	return (solution);
}

BOOL			check_availible_path(t_path **result, size_t index)
{
	t_path_list *list_paths;
	t_path *tmp;
	size_t i;

	list_paths = g_saved_path[index];
	i = 0;
	while (i < list_paths->size)
	{
		tmp = t_path_list_at(list_paths, i);
		if (t_room_list_at(tmp->path, tmp->path->size - 1)->occuped == FALSE)
		{
			*result = tmp;
			return (TRUE);
		}
		i++;
	}
	*result = NULL;
	return (FALSE);
}

static void create_saved_path(t_map *map)
{
	size_t i;

	g_saved_path = malloc(sizeof(t_path_list) * map->to_calc->size);
	if (g_saved_path == NULL)
		error_exit(1, "Can't malloc a t_path_list");
	i = 0;
	while (i < map->to_calc->size)
	{
		g_saved_path[i] = malloc_path_list(50);
		i++;
	}
}

void				calc_next_valid_path(t_map *map, t_solution *solution, size_t index)
{
	t_path	*path;
	t_room	*to_test;

	if (g_saved_path == NULL)
		create_saved_path(map);
	to_test = t_room_list_at(map->to_calc, index);
	if (to_test->occuped == FALSE)
	{
		to_test->occuped = TRUE;
		if (check_availible_path(&path, index) == FALSE)
			path = calc_path(map, to_test);
		if (path != NULL)
		{
			t_path_list_add(g_saved_path[index], path);
			add_path_to_solution(solution, path);
		}
	}
}

t_solution		*calc_solution(t_map *map, int *value_list)
{
	static t_solution *solution = NULL;
	size_t		j;
	t_room *room;

	j = 0;
	while (j < map->to_calc->size)
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
	while (j < map->to_calc->size)
	{
		room = t_room_list_at(map->to_calc, value_list[j]);
		calc_next_valid_path(map, solution, value_list[j]);
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
		if (tmp != NULL && tmp->note < result->note)
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

static void add_mono_path(t_map *map, t_solution *saved_solution)
{
	t_path *path;
	size_t index;

	reset_map_occupation(map);
	calc_distance(map);
	index = 0;
	while (index < map->mono_path->size)
	{
		path = calc_path(map, map->mono_path->content[index]);
		add_path_to_solution(saved_solution, path);
		index++;
	}
}

void		multi_path_solver(t_map *map, t_solution *saved_solution)
{
	reset_map_occupation(map);
	calc_distance(map);
	if (map->to_calc->size == 0)
		*saved_solution = create_solution();
	else
		generate_optimial_solution(map, saved_solution, 0, map->to_calc->size);

	ft_printf("Tmp solution\n");
	print_solution(saved_solution);

	add_mono_path(map, saved_solution);
	calc_solution_note(map, saved_solution);
	reverse_solution(saved_solution);
}

void desactive_solo(t_map *map)
{
	t_path *path[2];
	t_room_list *tmp;
	size_t index[2];
	BOOL found;

	tmp = map->to_calc;
	map->to_calc = malloc_room_list(map->end->links->size);
	map->mono_path = malloc_room_list(map->end->links->size);
	index[0] = 0;
	while (index[0] < tmp->size)
	{
		reset_map_occupation(map);
		calc_distance(map);
		path[0] = calc_path(map, tmp->content[index[0]]);
		found = FALSE;
		index[1] = index[0] + 1;
		while (index[1] < tmp->size)
		{
			if (index[0] != index[1])
			{
				path[1] = calc_path(map, tmp->content[index[1]]);
				if (path[1] == NULL)
					found = TRUE;
			}
			index[1]++;
		}
		if (found == TRUE)
			t_room_list_add(map->to_calc, tmp->content[index[0]]);
		else
			t_room_list_add(map->mono_path, tmp->content[index[0]]);
		index[0]++;
	}
	free_room_list(tmp);
}

void desactivate_useless(t_map *map, size_t base_len)
{
	t_path *path;
	size_t i;
	t_room *tmp;

	(void)base_len;
	map->to_calc = malloc_room_list(map->end->links->size);
	i = 0;
	while (i < map->end->links->size)
	{
		reset_map_occupation(map);
		calc_distance(map);
		tmp = t_room_list_at(map->end->links, i);
		path = calc_path(map, tmp);
		if (path != NULL && path->path->size <= base_len)
			t_room_list_add(map->to_calc, tmp);
		i++;
	}
}

t_solution				solver(t_map *map)
{
	t_solution	solution;

	calc_distance(map);
	solution = single_path_solver(map, calc_path(map, map->end));
	desactivate_useless(map, solution.paths.content[0]->path->size + map->nb_fourmis / (map->nb_fourmis / 10));
	desactive_solo(map);
	// ft_printf("To calc:\n");
	// print_room_list(map->to_calc);
	// ft_printf("\n\nmono_path :\n");
	// print_room_list(map->mono_path);
	// ft_printf("\n\n");
	multi_path_solver(map, &solution);
	return (solution);
}
