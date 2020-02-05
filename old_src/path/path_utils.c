/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:49:48 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/04 18:37:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** calc_next_room utilite :
** recupere la room qui a la plus petite distance de la liste des chemins de
** la room actual
*/

static t_room	*calc_next_room(t_room *actual)
{
	t_room	*next;
	size_t	j;
	t_room	*tmp;

	next = NULL;
	j = 0;
	while (j < actual->parent->size)
	{
		tmp = t_room_list_at(actual->parent, j);
		if (tmp->occuped == FALSE)
		{
			if (next == NULL)
				next = tmp;
			else if (tmp->distance < actual->distance && tmp->distance < next->distance)
				next = tmp;
		}
		j++;
	}
	return (next);
}

t_path			*calc_path(t_map *map, t_room *departure)
{
	size_t			i;
	t_room_list	*tmp_path;
	t_room			*room[2];

	tmp_path = malloc_room_list(map->room_list->size);
	if (departure != map->end)
		t_room_list_add(tmp_path, map->end);
	t_room_list_add(tmp_path, departure);
	i = tmp_path->size - 1;
	while (i < tmp_path->size)
	{
		room[0] = t_room_list_at(tmp_path, i);
		if (room[0]->distance != 0)
		{
			room[1] = calc_next_room(room[0]);
			if (room[1] == NULL)
			{
				free_room_list(tmp_path);
				return (NULL);
			}
			t_room_list_add(tmp_path, room[1]);
			room[1]->occuped = (room[1]->distance != 0 ? TRUE : FALSE);
		}
		i++;
	}
	return (malloc_path(tmp_path));
}

void			reverse_path(t_path *path)
{
	t_room_list *tmp;
	t_room		*tmp2;
	size_t		i;
	size_t		j;

	i = 0;
	tmp = path->path;
	j = tmp->size - 1;
	while (i < j)
	{
		tmp2 = tmp->content[i];
		tmp->content[i] = tmp->content[j];
		tmp->content[j] = tmp2;
		i++;
		j--;
	}
}

void			copy_path(t_path *dest, t_path *src)
{
	size_t	i;

	i = 0;
	dest->path->size = 0;
	while (i < src->path->size)
	{
		t_room_list_add(dest->path, t_room_list_at(src->path, i));
		i++;
	}
}
