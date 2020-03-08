/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:10:44 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 12:59:56 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

BOOL		is_all_path_same_len(t_list *paths)
{
	size_t	i;
	t_path	*tmp_path;
	size_t	saved_len;

	i = 0;
	saved_len = 0;
	while (i < paths->size)
	{
		tmp_path = list_at(paths, i);
		if (saved_len == 0)
			saved_len = tmp_path->road->size + tmp_path->count;
		else if (saved_len != tmp_path->road->size + tmp_path->count)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

size_t		nb_fourmi_placed(t_list *paths)
{
	size_t	i;
	t_path	*tmp_path;
	size_t	result;

	i = 0;
	result = 0;
	while (i < paths->size)
	{
		tmp_path = list_at(paths, i);
		result += tmp_path->count;
		i++;
	}
	return (result);
}

static void	add_left_fourmis(t_map *map, t_list *paths)
{
	size_t	i;
	t_path	*tmp_path;
	size_t	left;

	left = (map->nb_fourmis - nb_fourmi_placed(paths)) / paths->size;
	i = 0;
	while (i < paths->size)
	{
		tmp_path = list_at(paths, i);
		tmp_path->count += left;
		i++;
	}
	i = nb_fourmi_placed(paths);
	while ((int)i < map->nb_fourmis)
	{
		tmp_path = get_shorter_path(paths);
		if (tmp_path != NULL)
			tmp_path->count++;
		i++;
	}
}

void		prepare_path(t_map *map, t_list *paths)
{
	size_t	i;
	t_path	*tmp_path;

	if (map == NULL || paths == NULL || paths->size == 0)
		return ;
	i = 0;
	while (i < paths->size)
	{
		tmp_path = list_at(paths, i);
		tmp_path->count = 0;
		i++;
	}
	i = 0;
	while ((int)i < map->nb_fourmis && is_all_path_same_len(paths) == FALSE)
	{
		tmp_path = get_shorter_path(paths);
		if (tmp_path != NULL)
			tmp_path->count++;
		i++;
	}
	if (is_all_path_same_len(paths) == FALSE)
		return ;
	add_left_fourmis(map, paths);
}
