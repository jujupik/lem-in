/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 23:30:47 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	create_room(char *p_name, t_room_state p_status, int x, int y)
{
	t_room	result;

	result.name = ft_strdup(p_name);
	result.x = x;
	result.y = y;
	result.status = p_status;
	result.links = malloc_ptr_room_list(500);
	result.self_links = malloc_ptr_room_list(500);
	result.distance = UINT_MAX;
	result.occuped = FALSE;
	result.fourmis = NULL;
	return (result);
}

t_room	*malloc_room(char *p_name, t_room_state p_status, int x, int y)
{
	t_room	*result;

	result = (t_room *)malloc(sizeof(t_room));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_room");
	*result = create_room(p_name, p_status, x, y);
	return (result);
}

void	destroy_room(t_room to_destroy)
{
	free(to_destroy.name);
	free_ptr_room_list(to_destroy.links);
	free_ptr_room_list(to_destroy.self_links);
}

void	free_room(t_room *to_free)
{
	destroy_room(*to_free);
	free(to_free);
}

void	room_add_link(t_room *a, t_room *b)
{
	size_t	i;
	BOOL	found;

	i = 0;
	found = FALSE;
	while (i < a->links->size && found == FALSE)
	{
		if (t_ptr_room_list_at(a->links, i) == b)
			found = TRUE;
		i++;
	}
	if (found == FALSE)
	{
		t_ptr_room_list_add(a->links, b);
		t_ptr_room_list_add(a->self_links, b);
		t_ptr_room_list_add(b->links, a);
	}
}
