/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:01:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/22 18:01:28 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*state_str(t_room_state state)
{
	if (state == normal)
		return ("normal");
	if (state == start)
		return ("start");
	if (state == end)
		return ("end");
	return ("error");
}
