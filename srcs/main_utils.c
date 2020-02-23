/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:01:59 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 13:47:06 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reverse_path(t_path *path)
{
	t_list		*list;
	void		*tmp;
	size_t		i;

	i = 0;
	list = path->road;
	while (i < list->size / 2)
	{
		tmp = list_at(list, i);
		*(list_get(list, i)) = list_at(list, list->size - 1 - i);
		*(list_get(list, list->size - 1 - i)) = tmp;
		i++;
	}
}

t_link	*search_link(t_room *actual, t_room *dest)
{
	size_t	i;
	t_link	*link;

	link = NULL;
	i = 0;
	while (i < actual->links->size)
	{
		link = list_at(actual->links, i);
		if (ft_strcmp(link->children->name, dest->name) == TRUE ||
			ft_strcmp(link->parent->name, dest->name) == TRUE)
			return (link);
		i++;
	}
	return (NULL);
}
