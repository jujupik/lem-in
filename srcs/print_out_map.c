/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:09:50 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 21:23:03 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void print_out_link(t_room *room)
{
	size_t	i;
	t_room	*tmp;

	i = 0;
	while (i < room->self_links->size)
	{
		tmp = t_ptr_room_list_at(room->self_links, i);
		ft_printf("%s-%s\n", room->name, tmp->name);
		i++;
	}
}

void print_out_map(t_map *map)
{
	size_t i;
	t_room *room;

	ft_printf("%d\n", map->nb_fourmis);
	i = 0;
	while (i < map->room_list->size)
	{
		room = t_room_list_get(map->room_list, i);
		if (room->status == start)
			ft_printf("##start\n");
		if (room->status == end)
			ft_printf("##end\n");
		ft_printf("%s %d %d\n", room->name, room->x, room->y);
		i++;
	}
	i = 0;
	while (i < map->room_list->size)
	{
		room = t_room_list_get(map->room_list, i);
		print_out_link(room);
		i++;
	}
}
