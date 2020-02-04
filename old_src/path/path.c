/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:49:48 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/01 00:23:26 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			create_path(t_room_list *p_path)
{
	t_path result;

	result.path = p_path;
	result.count = 0;
	return (result);
}

t_path			*malloc_path(t_room_list *p_path)
{
	t_path	*result;

	result = (t_path *)malloc(sizeof(t_path));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_path");
	*result = create_path(p_path);
	return (result);
}

void 			destroy_path(t_path to_destroy)
{
	free_room_list(to_destroy.path);
}

void 			free_path(t_path *to_free)
{
	destroy_path(*to_free);
	free(to_free);
}
