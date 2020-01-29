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

t_str_list	create_str_list(size_t p_push_size)
{
	t_str_list result;

	result.push_size = p_push_size;
	result.max_size = result.push_size;
	result.content = malloc(sizeof(t_str) * result.max_size);
	if (result.content == NULL)
		error_exit(-2, "can't malloc str list");
	result.size = 0;
	return (result);
}

void			free_str_list(t_str_list list)
{
	free(list.content);
}

void			t_str_list_add(t_str_list *list, t_str to_add)
{
	char		*tmp2;
	t_str		*tmp;
	size_t		i;

	if (list->size == list->max_size - 1)
	{
		tmp = list->content;
		list->max_size += list->push_size;
		list->content = malloc(sizeof(t_str) * list->max_size);
		i = 0;
		while (i < list->size)
		{
			list->content[i] = tmp[i];
			i++;
		}
		free(tmp);
	}
	tmp2 = ft_strdup(to_add);
	list->content[list->size] = tmp2;
	list->size++;
}

t_str			t_str_list_at(t_str_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}
