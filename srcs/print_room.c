/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:31:15 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 22:19:25 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_room(t_room *room)
{
	t_link	*link;
	char	*dist_str;
	size_t	i;

	dist_str = ft_itoa((long long)room->distance);
	ft_printf("{%*s} - [%6b] - [%*s] - {%5s} - {%9s} -> [total : %2d\
(%2d / %2d)] - ", g_name_max_len, room->name, room->active,\
			g_max_distance, room->distance == UINT_MAX ? "" : dist_str,\
			(room->previous == NULL ? "null" : room->previous->name), \
			state_str(room->state), room_flow_total(room),\
			room_flow_children(room), room_flow_parent(room));
	free(dist_str);
	i = 0;
	while (i < room->links->size)
	{
		link = list_at(room->links, i);
		if (i != 0)
			ft_printf(" - ");
		print_link(room, link);
		i++;
	}
	ft_printf("\n");
}

void		print_link(t_room *room, t_link *link)
{
	if (ft_abs(link->flow) > 1)
		ft_printf("\033[0;31m");
	else if (ft_abs(link->flow) == 1)
		ft_printf("\033[0;32m");
	ft_printf("%*s[%2d]", g_name_max_len, (link->children != room ?\
		link->children->name : link->parent->name), link->flow);
	ft_printf("\033[0m");
}
