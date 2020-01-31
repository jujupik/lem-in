/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:49:58 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 16:50:38 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_nb_fourmis(t_map *map)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0 && line_is_commentary(line) == TRUE) //on lit les premiere lignes jusqu'a tomber sur celle qui n'est pas un commentaire
		;
	if (line == NULL) //erreur si y'a pas de ligne
		error_exit(0, "Nothing in the map");
	if (line_is_command(line) == TRUE) //erreur si c'est une commande
		error_exit(0, "Command line before ant number");
	if (ft_strisdigit(line) == FALSE) //erreur si c'est pas juste un nombre
		error_exit(0, "Nb ant line isn't fully digit");
	map->nb_fourmis = ft_atoi(line); // on passe le nb lu dans nb_fourmis
	free(line);
}

void	parse_room(t_map *map, char *line, t_room_state *status)
{
	char	**tab;
	t_room	*actual;

	tab = ft_strsplit(line, ' '); //on split pour avoir les param description en 3 partie
	if (is_name_valid(map->room_list, tab[0]) == FALSE) //si nom commence par un L, a un espace ou -: cas erreur
		error_exit(1, "Bad room name");
	t_room_list_add(map->room_list, create_room(tab[0], *status)); //on rajoute le nom de cette room, son statu a la liste des rooms(et on lui malloc une lst pour futur lien)
	actual = t_room_list_get(map->room_list, map->room_list->size - 1); //on recupere la room qu'on vient de creer
	if (*status == start) // si la room est juste apres un ##start, donc son statu start
	{
		if (map->start != NULL)
			map->start->status = normal; //si ecrase room remplacer dans la lst des rooms le status de la precedente
		map->start = actual; //on set map->start avec room
	}
	if (*status == end) //pareil pour ##end
	{
		if (map->end != NULL)
			map->end->status = normal;
		map->end = actual;
	}
	*status = normal; // on reset le status par defaut
	ft_tab_free(tab);
}

void	parse_command(char *line, t_room_state *status) // set le status a sa commande
{
	if (ft_strcmp(line, "##start") == 0)
		*status = start;
	else if (ft_strcmp(line, "##end") == 0)
		*status = end;
}

t_room	*search_room(t_map *map, char *room_name) //parcour la liste des rooms, si room_name presente on renvoi la room correspondante
{
	t_room	*room;
	size_t	i;

	i = 0;
	while (i < map->room_list->size)
	{
		room = t_room_list_get(map->room_list, i);
		if (ft_strcmp(room->name, room_name) == 0)
			return (room);
		i++;
	}
	return (NULL);
}

void	parse_link(t_map *map, char *line, BOOL *utils)
{
	char	**tab;
	t_room	*a;
	t_room	*b;

	if (map->start == NULL || map->end == NULL)
		error_exit(0, "No start or end in map");
	tab = ft_strsplit(line, '-'); //tab[0]-tab[1]
	a = search_room(map, tab[0]); //a = la room tab[0] de la liste room si correspondance
	b = search_room(map, tab[1]); // b pareil tab[1]
	if (a != NULL && b != NULL)
		room_add_link(a, b); // si room valide on la rajoute a la liste chemins
	else
		*utils = FALSE; //si room inexistante alors mauvaise ligne
	ft_tab_free(tab);
}
