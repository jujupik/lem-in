/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:49:48 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 22:44:06 by jrouchon         ###   ########.fr       */
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
	while (j < actual->links->size)
	{
		tmp = t_ptr_room_list_at(actual->links, j);
		if ((next == NULL || next->distance > tmp->distance) &&
			tmp->occuped == FALSE)
			next = tmp;
		j++;
	}
	return (next);
}

t_path			calc_path(t_map *map, t_room *departure)
{
	size_t			i;
	t_ptr_room_list	result;
	t_room			*room[2];

	result = create_ptr_room_list(map->room_list->size);
	t_ptr_room_list_add(&result, map->end);
	t_ptr_room_list_add(&result, departure);
	i = 1;
	while (i < result.size)
	{
		room[0] = t_ptr_room_list_at(&result, i);
		if (room[0]->distance != 0)
		{
			room[1] = calc_next_room(room[0]);
			if (room[1] == NULL)
			{
				destroy_ptr_room_list(result);
				return (create_ptr_room_list(0));
			}
			t_ptr_room_list_add(&result, room[1]);
			room[1]->occuped = (room[1]->distance != 0 ? TRUE : FALSE);
		}
		i++;
	}
	return (result);
}

void			print_path(t_path *path, char *name)
{
	size_t	i;
	t_room	*tmp;

	i = 0;
	ft_printf("%s :\n", name);
	if (path == NULL || path->size == 0)
		ft_printf("No path");
	else
	{
		while (i < path->size)
		{
			tmp = t_ptr_room_list_at(path, i);
			if (i != 0)
				ft_printf("-");
			ft_printf("%s", tmp->name);
			i++;
		}
	}
	ft_printf("\n");
}

void			reverse_path(t_path *path)
{
	t_ptr_room	tmp;
	size_t		i;
	size_t		j;

	i = 0;
	j = path->size - 1;
	while (i < j)
	{
		tmp = path->content[i];
		path->content[i] = path->content[j];
		path->content[j] = tmp;
		i++;
		j--;
	}
}
