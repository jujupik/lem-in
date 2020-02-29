/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 15:48:51 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t g_name_len = 1;

t_room	create_room(char *p_name, t_room_state p_state, int x, int y)
{
	t_room	result;

	result.name = ft_strdup(p_name);
	if (ft_strlen(result.name) > g_name_len)
		g_name_len = ft_strlen(result.name);
	result.apparition = 0;
	result.x = x;
	result.y = y;
	result.previous = NULL;
	result.active = FALSE;
	result.distance = UINT_MAX;
	result.state = p_state;
	result.links = malloc_list(100);
	result.my_link = malloc_list(100);
	return (result);
}

t_room	*malloc_room(char *p_name, t_room_state p_state, int x, int y)
{
	t_room	*result;

	result = (t_room *)ft_malloc(sizeof(t_room));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_room");
	*result = create_room(p_name, p_state, x, y);
	return (result);
}

void	destroy_room(t_room to_destroy)
{
	ft_free(to_destroy.name);
	free_list(to_destroy.my_link, tmp_free_link);
	free_list(to_destroy.links, NULL);
}

void	free_room(t_room *to_free)
{
	if (to_free != NULL)
		destroy_room(*to_free);
	ft_free(to_free);
}

void	add_room_link(t_room *parent, t_room *children)
{
	t_link	*p_link;
	size_t	i;

	if (search_link(parent, children) != NULL)
		return ;
	i = 0;
	while (i < parent->links->size)
	{
		p_link = list_at(parent->links, i);
		if (p_link->parent == children || p_link->children == children)
			return ;
		i++;
	}
	p_link = malloc_link(parent, children);
	list_push_back(parent->my_link, p_link);
	list_push_back(parent->links, p_link);
	list_push_back(children->links, p_link);
}
