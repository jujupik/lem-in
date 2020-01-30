/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:10:29 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 14:10:30 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	draw_links(t_ptr_room_list *links)
{
	size_t j;

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

void		print_map(t_map *map)
{
	t_room	*room;
	size_t	i;

	// ft_printf("nb fourmis : %d\n\n", map->nb_fourmis);
	// ft_printf("start room : %s\n",
	// 	(map->start == NULL ? "(null)" : map->start->name));
	// ft_printf("end room : %s\n\n",
	// 	(map->end == NULL ? "(null)" : map->end->name));
	i = 0;
	while (i < map->room_list->size)
	{
		room = t_room_list_get(map->room_list, i);
		ft_printf("[%7u] - {%3s} - {%9s} - {%9s} - [%4u]\n", i, room->name,
						(room->status == normal ? "Normal" :
						(room->status == start ? "Start" : "End")),
						(room->occuped == TRUE ? "occuped" : "empty"),
						room->distance);
		//draw_links(room->links);
		i++;
	}
}
