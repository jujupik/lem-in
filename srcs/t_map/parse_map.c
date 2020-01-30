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
	BOOL			links;

	line = NULL;
	utils = TRUE;
	links = FALSE;
	status = normal;
	while (get_next_line(0, &line) > 0 && utils == TRUE) //on lit tant qu'on a des lignes valides
	{
		if (line_is_room(line) == TRUE && links == FALSE) //si c'est une room et avec un bon nb de param de description
			parse_room(map, line, &status); //on parse la ligne on la passe dans la map avec son status (qui est normal par defaut)
		else if (line_is_command(line) == TRUE && links == FALSE) //si c'est une commande donc commence par ##
			parse_command(line, &status); //si commande == ##start ou ##end set le status correspondant
		else if (line_is_link(line) == TRUE) //si c'est un chemin donc format room-otherroom
		{
			parse_link(map, line, &utils);  //parse la ligne, rajoute les chemins dans la lst chemin des rooms, set utils FALSE si invalide
			links = TRUE;
		}
		else if (line_is_commentary(line) == FALSE) // si cest pas un commentaire (format #bla) ni le reste alors erreur
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
