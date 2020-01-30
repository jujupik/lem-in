/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_str_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:49:32 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/24 16:49:35 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

void				t_intstr_list_add(t_intstr_list *list, t_int_array to_add)
{
	t_int_array	*tmp;
	size_t		i;

	if (list->size == list->max_size - 1)
	{
		tmp = list->content;
		list->max_size += list->push_size;
		list->content = malloc(sizeof(t_int_array) * list->max_size);
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

t_int_array			t_intstr_list_at(t_intstr_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}
