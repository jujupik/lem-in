/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:49:59 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 19:50:44 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_map_content(t_map *map)
{
	char			*line;
	t_room_state	status;
	BOOL			utils;
	BOOL			links;

	line = NULL;
	utils = TRUE;
	links = FALSE;
	status = normal;
	while (get_next_line(0, &line) > 0 && utils == TRUE)
	{
		if (line_is_room(line) == TRUE && links == FALSE)
			parse_room(map, line, &status);
		else if (line_is_command(line) == TRUE && links == FALSE)
			parse_command(line, &status);
		else if (line_is_link(line) == TRUE)
		{
			parse_link(map, line, &utils);
			links = TRUE;
		}
		else if (line_is_commentary(line) == FALSE)
			error_exit(1, "Bad map line");
	}
	free(line);
}

void	parse_map(t_map *map)
{
	parse_nb_fourmis(map);
	parse_map_content(map);
	map->end->occuped = TRUE;
}
