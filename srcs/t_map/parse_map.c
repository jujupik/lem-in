/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:10:06 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 14:10:08 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_map_content(t_map *map)
{
	char			*line;
	t_room_state	status;
	BOOL			utils;

	line = NULL;
	utils = TRUE;
	while (get_next_line(0, &line) > 0 && utils == TRUE)
	{
		if (line_is_piece(line) == TRUE)
			parse_piece(map, line, &status);
		else if (line_is_command(line) == TRUE)
			parse_command(line, &status);
		else if (line_is_link(line) == TRUE)
			parse_link(map, line, &utils);
		else if (line_is_commentary(line) == FALSE)
			error_exit(1, "Bad map line");
	}
}

void	parse_map(t_map *map)
{
	parse_nb_fourmis(map);
	parse_map_content(map);
}
