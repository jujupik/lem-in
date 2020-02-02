/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_path_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:49:52 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/02 21:35:53 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			*t_path_list_at(t_path_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}

t_path			**t_path_list_get(t_path_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (&(list->content[index]));
}

void			clear_path_list(t_path_list *path)
{
	t_path *tmp;
	size_t i;

	i = 0;
	while (i < path->size)
	{
		tmp = t_path_list_at(path, i);
		free_path(tmp);
		i++;
	}
	path->size = 0;
}

void			copy_path_list(t_path_list *dest, t_path_list *src)
{
	t_ptr_room_list *tmp;
	t_path *path_dest;
	t_path *path_src;
	size_t	i;
	size_t	j;

	i = 0;
	clear_path_list(dest);
	while (i < src->size)
	{
		path_src = t_path_list_at(src, i);
		tmp = malloc_ptr_room_list(path_src->path->size);
		j = 0;
		while (j < path_src->path->size)
		{
			t_ptr_room_list_add(tmp, t_ptr_room_list_at(path_src->path, j));
			j++;
		}
		path_dest = malloc_path(tmp);
		path_dest->count = path_src->count;
		t_path_list_add(dest, path_dest);
		i++;
	}
}
