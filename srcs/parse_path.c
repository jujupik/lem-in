/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 12:55:01 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t			solution_note(t_list *paths)
{
	t_path	*tmp;

	tmp = get_longuest_path(paths);
	if (tmp == NULL)
		return (0);
	return (tmp->road->size + tmp->count - 2);
}

static void		tmp_destroy_funct(void *param)
{
	free_path((t_path *)param);
}

static int		tmp_parse_path(t_list **result, t_list *tmp)
{
	if ((*result) == NULL || solution_note(tmp) < solution_note((*result)))
	{
		if ((*result) != NULL)
			free_list((*result), tmp_destroy_funct);
		(*result) = tmp;
	}
	else
	{
		free_list(tmp, tmp_destroy_funct);
		return (-1);
	}
	return (0);
}

t_list			*parse_path(t_map *map)
{
	t_list	*result;
	t_list	*tmp;
	t_path	*path;
	size_t	i;

	i = 0;
	result = NULL;
	while (i < map->start->links->size)
	{
		reset_distance(map);
		calc_distance(map->start);
		path = get_path(map->end);
		if (path != NULL)
			active_path(path);
		tmp = find_all_path(map);
		prepare_path(map, tmp);
		free_path(path);
		if (tmp_parse_path(&result, tmp) == -1)
			return (result);
		i++;
	}
	return (result);
}
