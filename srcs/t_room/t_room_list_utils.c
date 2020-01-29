/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:11:30 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 14:11:32 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			t_room_list_at(t_room_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}

t_room			*t_room_list_get(t_room_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (&(list->content[index]));
}
