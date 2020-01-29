/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_vector2_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:49:32 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/24 16:49:35 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

t_vector2_list	create_vector2_list(size_t p_push_size)
{
	t_vector2_list result;

	result.push_size = p_push_size;
	result.max_size = result.push_size;
	result.content = malloc(sizeof(t_vector2) * result.max_size);
	if (result.content == NULL)
		error_exit(-2, "can't malloc vector2 list");
	result.size = 0;
	return (result);
}

void			free_vector2_list(t_vector2_list list)
{
	free(list.content);
}

void			t_vector2_list_add(t_vector2_list *list, t_vector2 to_add)
{
	t_vector2	*tmp;
	size_t		i;

	if (list->size == list->max_size - 1)
	{
		tmp = list->content;
		list->max_size += list->push_size;
		list->content = malloc(sizeof(t_vector2) * list->max_size);
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

t_vector2		t_vector2_list_at(t_vector2_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}
