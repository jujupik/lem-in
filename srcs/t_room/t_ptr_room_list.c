/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_ptr_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:49:32 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/24 16:49:35 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ptr_room_list	create_ptr_room_list(size_t p_push_size)
{
	t_ptr_room_list result;

	result.push_size = p_push_size;
	result.max_size = result.push_size;
	result.content = malloc(sizeof(t_ptr_room) * result.max_size);
	if (result.content == NULL)
		error_exit(-2, "can't malloc ptr_room list");
	result.size = 0;
	return (result);
}

t_ptr_room_list	*malloc_ptr_room_list(size_t p_push_size)
{
	t_ptr_room_list	*result;

	result = (t_ptr_room_list *)malloc(sizeof(t_ptr_room_list));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_ptr_room");
	*result = create_ptr_room_list(p_push_size);
	return (result);
}

void			destroy_ptr_room_list(t_ptr_room_list list)
{
	free(list.content);
}

void			free_ptr_room_list(t_ptr_room_list *list)
{
	destroy_ptr_room_list(*list);
	free(list);
}

void			t_ptr_room_list_add(t_ptr_room_list *list, t_ptr_room to_add)
{
	t_ptr_room		*tmp;
	size_t		i;

	if (list->size == list->max_size - 1)
	{
		tmp = list->content;
		list->max_size += list->push_size;
		list->content = malloc(sizeof(t_ptr_room) * list->max_size);
		i = 0;
		while (i < list->size)
		{
			list->content[i] = tmp[i];
			i++;
		}
		free(tmp);
	}
	list->content[list->size] = to_add;
	list->size++;
}

t_ptr_room			t_ptr_room_list_at(t_ptr_room_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}

t_ptr_room			*t_ptr_room_list_get(t_ptr_room_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (&(list->content[index]));
}
