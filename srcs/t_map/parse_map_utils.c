/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:10:14 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 14:10:15 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_nb_fourmis(t_map *map)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0 && line_is_commentary(line) == TRUE)
		;
	if (line == NULL)
		error_exit(0, "Nothing in the map");
	if (line_is_command(line) == TRUE)
		error_exit(0, "Command line before ant number");
	if (ft_strisdigit(line) == FALSE)
		error_exit(0, "Nb ant line isn't fully digit");
	map->nb_fourmis = ft_atoi(line);
}

void	parse_piece(t_map *map, char *line, t_room_state *status)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (is_name_valid(map->room_list, tab[0]) == FALSE)
		error_exit(1, "Bad piece name");
	t_room_list_add(map->room_list, create_room(tab[0], *status));
	if (*status == start)
		map->start = t_room_list_get(map->room_list, map->room_list->size - 1);
	if (*status == end)
		map->end = t_room_list_get(map->room_list, map->room_list->size - 1);
	*status = normal;
	ft_tab_free(tab);
}

void	parse_command(char *line, t_room_state *status)
{
	if (ft_strcmp(line, "##start") == 0)
		*status = start;
	else if (ft_strcmp(line, "##end") == 0)
		*status = end;
}

t_room	*search_room(t_map *map, char *room_name)
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

	tab = ft_strsplit(line, '-');
	a = search_room(map, tab[0]);
	b = search_room(map, tab[1]);
	if (a != NULL && b != NULL)
		room_add_link(a, b);
	else
		*utils = FALSE;
}
