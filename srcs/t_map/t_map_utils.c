/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:07 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 16:50:08 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_links(t_ptr_room_list *links)
{
	size_t	j;

	if (links->size == 0)
		ft_printf("	Links : (NO LINKS)\n");
	else
	{
		ft_printf("	Links : ");
		j = 0;
		while (j < links->size)
		{
			if (j != 0)
				ft_printf(" - ");
			ft_printf("(%s)", t_ptr_room_list_at(links, j)->name);
			j++;
		}
		ft_printf("\n");
	}
}

static char	*status_str(t_room_state status)
{
	if (status == start)
		return ("start");
	else if (status == end)
		return ("end");
	else
		return ("normal");
}

void		print_map(t_map *map)
{
	t_room	*room;
	size_t	i;

	i = 0;
	while (i < map->room_list->size)
	{
		room = t_room_list_get(map->room_list, i);
		ft_printf("[%7u] - {%3s} - {%9s} - {%9s} - [%4u]\n", i, room->name,
			status_str(room->status),
			(room->occuped == TRUE ? "occuped" : "empty"),
			room->distance);
		i++;
	}
}

void		reset_map_occupation(t_map *map)
{
	t_room	*room;
	size_t	i;

	i = 0;
	while (i < map->room_list->size)
	{
		room = t_room_list_get(map->room_list, i);
		room->occuped = FALSE;
		i++;
	}
	map->end->occuped = TRUE;
}
