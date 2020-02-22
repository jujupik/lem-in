/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:46:00 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/22 17:50:52 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			create_path(void)
{
	t_path	result;

	result.road = malloc_list(500);
	result.count = 0;
	return (result);
}

t_path			*malloc_path(void)
{
	t_path	*result;

	result = (t_path *)malloc(sizeof(t_path));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_path");
	*result = create_path();
	return (result);
}

void			destroy_path(t_path to_destroy)
{
	free_list(to_destroy.road, NULL);
}

void			free_path(t_path *to_free)
{
	destroy_path(*to_free);
	free(to_free);
}

void			add_room_to_path(t_path *path, t_room *room)
{
	list_push_back(path->road, room);
}
