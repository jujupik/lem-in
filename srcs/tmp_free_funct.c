/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_free_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 14:39:20 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	tmp_free_room(void *room)
{
	free_room(room);
}

void	tmp_free_path(void *path)
{
	free_path(path);
}

void	tmp_free_link(void *link)
{
	free_link(link);
}
