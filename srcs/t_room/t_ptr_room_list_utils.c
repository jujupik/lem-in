/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ptr_room_list_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:10:56 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 14:10:57 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ptr_room			t_ptr_room_list_at(t_ptr_room_list *list, size_t index) //l'index de l'elem room
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}
