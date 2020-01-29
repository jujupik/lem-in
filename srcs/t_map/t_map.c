/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:10:23 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 14:10:25 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map	create_map(void)
{
	t_map result;

	result.nb_fourmis = 0;
	result.room_list = malloc_room_list(500);
	result.start = NULL;
	result.end = NULL;
	return (result);
}

t_map	*malloc_map(void)
{
	t_map	*result;

	result = (t_map *)malloc(sizeof(t_map));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_map");
	*result = create_map();
	return (result);
}

void	destroy_map(t_map to_destroy)
{
	free_room_list(to_destroy.room_list);
}

void	free_map(t_map *to_free)
{
	destroy_map(*to_free);
	free(to_free);
}
