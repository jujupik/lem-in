/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:49:58 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 19:46:21 by jrouchon         ###   ########.fr       */
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
	free(line);
}

void	parse_room(t_map *map, char *line, t_room_state *status)
{
	char	**tab;
	t_room	*actual;

	tab = ft_strsplit(line, ' ');
	if (is_name_valid(map->room_list, tab[0]) == FALSE)
		error_exit(1, "Bad room name");
	t_room_list_add(map->room_list, create_room(tab[0], *status));
	actual = t_room_list_get(map->room_list, map->room_list->size - 1);
	if (*status == start)
	{
		if (map->start != NULL)
			map->start->status = normal;
		map->start = actual;
	}
	if (*status == end)
	{
		if (map->end != NULL)
			map->end->status = normal;
		map->end = actual;
	}
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

	if (map->start == NULL || map->end == NULL)
		error_exit(0, "No start or end in map");
	tab = ft_strsplit(line, '-');
	a = search_room(map, tab[0]);
	b = search_room(map, tab[1]);
	if (a != NULL && b != NULL)
		room_add_link(a, b);
	else
		*utils = FALSE;
	ft_tab_free(tab);
}
