/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:17 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 01:34:47 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*t_room_list_at(t_room_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}

t_room			**t_room_list_get(t_room_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (&(list->content[index]));
}

void			print_room_list(t_room_list *room)
{
	t_room *tmp;
	size_t i;

	i = 0;
	while (i < room->size)
	{
		tmp = t_room_list_at(room, i);
		print_room(tmp, i);
		i++;
	}
}
