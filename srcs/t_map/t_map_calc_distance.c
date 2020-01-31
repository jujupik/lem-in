/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_calc_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:05 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 16:50:05 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void calc_room_distance(t_room *actual, size_t parent_distance)
{
	size_t i;
	t_room *tmp;

	actual->distance = parent_distance; //distance attitree a la room de depart donc 0
	i = 0;
	while (i < actual->links->size) //on parcour la lst des chemins
	{
		tmp = t_ptr_room_list_at(actual->links, i); //tmp = elem de la lst room
		if (tmp->distance > actual->distance + 1 && tmp->occuped == FALSE) //si la distance actuelle est plus grande que celle du prochain elem de la lst chemins
			calc_room_distance(tmp, actual->distance + 1); //recursive +1
		i++;
	}
}

void calc_distance(t_map *map)
{
	calc_room_distance(map->start, 0);
}
