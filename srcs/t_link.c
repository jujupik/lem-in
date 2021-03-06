/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_link.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 19:51:46 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	create_link(t_room *p_parent, t_room *p_children)
{
	t_link	result;

	result.parent = p_parent;
	result.children = p_children;
	result.actual_parent = NULL;
	result.ant = NULL;
	result.flow = 0;
	return (result);
}

t_link	*malloc_link(t_room *p_parent, t_room *p_children)
{
	t_link	*result;

	result = (t_link *)malloc(sizeof(t_link));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_link");
	*result = create_link(p_parent, p_children);
	return (result);
}

void	destroy_link(t_link to_destroy)
{
	(void)to_destroy;
}

void	free_link(t_link *to_free)
{
	if (to_free != NULL)
	{
		destroy_link(*to_free);
		free(to_free);
	}
}

void	swap_link(t_link *link)
{
	t_room	*tmp;

	tmp = link->parent;
	link->parent = link->children;
	link->children = tmp;
}
