/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:07 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 08:01:15 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_links(t_room_list *links)
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
			ft_printf("(%s)", t_room_list_at(links, j)->name);
			j++;
		}
		ft_printf("\n");
	}
}

char	*status_str(t_room_state status)
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
		room = t_room_list_at(map->room_list, i);
		print_room(room, i);
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
		room = t_room_list_at(map->room_list, i);
		room->occuped = FALSE;
		i++;
	}
	map->end->occuped = TRUE;
}
