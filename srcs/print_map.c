/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:31:15 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 16:57:40 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_map(t_map *map)
{
	t_room	*room;
	size_t	i;

	i = 0;
	while (i < map->room_list->size)
	{
		room = list_at(map->room_list, i);
		print_room(room);
		i++;
	}
	ft_printf("\n----\n");
}

void		print_path(t_path *tmp)
{
	t_room	*room;
	size_t	i;

	i = 0;
	ft_printf("Path %u : len %u / Nb fourmi %u\n", i, tmp->road->size,\
	tmp->count);
	while (i < tmp->road->size)
	{
		room = list_at(tmp->road, i);
		ft_printf("%s[%*s]", (i != 0 ? " - " : ""), g_name_max_len, room->name);
		i++;
	}
	ft_printf("\n");
}
