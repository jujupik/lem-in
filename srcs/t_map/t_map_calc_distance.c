/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_calc_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:05 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/02 22:38:51 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	calc_room_distance(t_room *actual, size_t parent_distance)
{
	size_t i;
	t_room *tmp;

	actual->distance = parent_distance;
	i = 0;
	while (i < actual->links->size)
	{
		tmp = t_ptr_room_list_at(actual->links, i);
		if (tmp->distance > actual->distance + 1)
			calc_room_distance(tmp, actual->distance + 1);
		i++;
	}
}

void	calc_distance(t_map *map)
{
	calc_room_distance(map->start, 0);
}
