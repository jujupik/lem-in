/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ptr_room_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:10:51 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 14:10:52 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path_list	create_path_list(size_t p_push_size)
{
	t_path_list result;

	result.push_size = p_push_size;
	result.max_size = result.push_size;
	result.content = malloc(sizeof(t_path) * result.max_size);
	if (result.content == NULL)
		error_exit(-2, "can't malloc path list");
	result.size = 0;
	return (result);
}

t_path_list	*malloc_path_list(size_t p_push_size)
{
	t_path_list	*result;

	result = (t_path_list *)malloc(sizeof(t_path_list));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_path");
	*result = create_path_list(p_push_size);
	return (result);
}

void			destroy_path_list(t_path_list list)
{
	size_t i;

	i = 0;
	while (i < list.size)
	{
		destroy_ptr_room_list(t_path_list_at(&list, i));
		i++;
	}
	free(list.content);
}

void			free_path_list(t_path_list *list)
{
	destroy_path_list(*list);
	free(list);
}

void			t_path_list_add(t_path_list *list, t_path to_add) //rajoute un chemin a lst (malloc pour si precedent malloc trop petit)
{
	t_path		*tmp;
	size_t			i;

	if (list->size == list->max_size - 1)
	{
		tmp = list->content;
		list->max_size += list->push_size;
		list->content = malloc(sizeof(t_path) * list->max_size);
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
