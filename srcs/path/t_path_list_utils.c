/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_path_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:49:52 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 19:23:14 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			t_path_list_at(t_path_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (list->content[index]);
}

t_path			*t_path_list_get(t_path_list *list, size_t index)
{
	if (index >= list->size)
		index = list->size - 1;
	return (&(list->content[index]));
}
