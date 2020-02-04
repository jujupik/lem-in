/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/04 17:51:24 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	create_room(char *p_name, t_room_state p_state, int x, int y)
{
	t_room	result;

	result.name = ft_strdup(p_name);
	result.x = x;
	result.y = y;
	result.state = p_state;
	result.parent = malloc_list(100);
	result.children = malloc_list(100);
	return (result);
}

t_room	*malloc_room(char *p_name, t_room_state p_state, int x, int y)
{
	t_room	*result;

	result = (t_room *)malloc(sizeof(t_room));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_room");
	*result = create_room(p_name, p_state, x, y);
	return (result);
}

void	destroy_room(t_room to_destroy)
{
	free(to_destroy.name);
}

void	free_room(t_room *to_free)
{
	destroy_room(*to_free);
	free(to_free);
}

void print_room(t_room *room)
{
	size_t j;

	ft_printf("{%3s} - {%9s} -> ", room->name, state_str(room->state));
	j = 0;
	while (j < room->children->size)
	{
		if (j != 0)
			ft_printf(" - ");
		print_link(list_at(room->children, j));
		j++;
	}
	ft_printf("\n");
}

void add_room_link(t_room *parent, t_room *children)
{
	t_link *p_link;

	p_link = malloc_link(parent, children);
	list_push_back(parent->children, p_link);
	list_push_back(children->parent, p_link);
}
