/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fourmis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:09:50 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 01:46:17 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_fourmis create_fourmis(size_t p_name, int p_path, int p_room)
{
	t_fourmis result;

	result.name = p_name;
	result.path_index = p_path;
	result.room_index = p_room;
	result.arrived = FALSE;
	return (result);
}

t_fourmis *malloc_fourmis(size_t p_name, int p_path, int p_room)
{
	t_fourmis	*result;

	result = (t_fourmis *)malloc(sizeof(t_fourmis));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_fourmis");
	*result = create_fourmis(p_name, p_path, p_room);
	return (result);
}

void destroy_fourmis(t_fourmis to_destroy)
{
	(void)to_destroy;
}

void free_fourmis(t_fourmis *to_free)
{
	destroy_fourmis(*to_free);
	free(to_free);
}

void print_fourmis(t_solution *solution, t_fourmis *fourmis)
{
	if (fourmis->path_index == -1)
		return ;
	ft_printf("L%u-%s", fourmis->name, t_room_list_at(t_path_list_at(&(solution->paths), fourmis->path_index)->path, fourmis->room_index)->name);
}
