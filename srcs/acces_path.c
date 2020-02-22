/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acces_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:08:36 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/22 18:08:56 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*get_shorter_path(t_list *paths)
{
	t_path	*tmp;
	t_path	*result;
	size_t	i;

	i = 0;
	result = NULL;
	while (i < paths->size)
	{
		tmp = list_at(paths, i);
		if (result == NULL || result->road->size + result->count >
			tmp->road->size + tmp->count)
			result = tmp;
		i++;
	}
	return (result);
}

t_path	*get_longuest_path(t_list *paths)
{
	t_path	*tmp;
	t_path	*result;
	size_t	i;

	i = 0;
	result = NULL;
	while (i < paths->size)
	{
		tmp = list_at(paths, i);
		if ((result == NULL || result->road->size + result->count <
			tmp->road->size + tmp->count) && tmp->count != 0)
			result = tmp;
		i++;
	}
	return (result);
}
