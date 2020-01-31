/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:17 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 16:50:18 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			t_room_list_at(t_room_list *list, size_t index) //renvoi un copie
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}

t_room			*t_room_list_get(t_room_list *list, size_t index) //renvoi l'elem
{
	if (index >= list->size)
		index = list->size - 1;
	return (&(list->content[index]));
}
