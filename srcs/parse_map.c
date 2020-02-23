/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:56:13 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 16:55:28 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t g_max_distance = 0;

static void		parse_fourmis(t_map *map)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (line_is_commentary(line) == FALSE)
			break ;
	}
	if (line == NULL || ft_strisdigit(line) == FALSE)
		error_exit(1, "Bad fourmis line");
	map->nb_fourmis = ft_atoi(line);
	list_push_back(map->map_string, ft_strdup(line));
	free(line);
}

void			parse_link(t_map *map, char *line, BOOL *end)
{
	t_room	*room_a;
	t_room	*room_b;
	char	**tab;

	if (line_is_link(line) == TRUE)
	{
		if (ft_strschr(line, "--") == TRUE)
		{
			*end = TRUE;
			return ;
		}
		tab = ft_strsplit(line, '-');
		if ((room_a = search_room(map, tab[0])) == NULL ||
			(room_b = search_room(map, tab[1])) == NULL)
		{
			*end = TRUE;
			return ;
		}
		add_room_link(room_a, room_b);
		if (room_a == map->end)
			swap_link(search_link(room_a, room_b));
		ft_tab_free(tab);
	}
	else if (line_is_commentary(line) == FALSE)
		*end = TRUE;
}

static void		parse_room(t_map *map, char *line)
{
	static t_room_state state = normal;

	if (line_is_command(line) == TRUE)
	{
		if (ft_strcmp(line, "##start") == TRUE)
			state = start;
		else if (ft_strcmp(line, "##end") == TRUE)
			state = end;
	}
	if (line_is_room(line) == TRUE)
		add_room(map, line, &state);
}

static void		parse_map_content(t_map *map)
{
	char	*line;
	BOOL	found;
	BOOL	end;

	end = FALSE;
	found = FALSE;
	line = NULL;
	while (get_next_line(0, &line) && end == FALSE)
	{
		if (found == FALSE && line_is_link(line) == TRUE)
			found = TRUE;
		if (found == TRUE)
			parse_link(map, line, &end);
		else
			parse_room(map, line);
		if (end == FALSE)
			list_push_back(map->map_string, ft_strdup(line));
	}
	free(line);
}

t_map			parse_map(void)
{
	t_map	map;

	map = create_map();
	parse_fourmis(&map);
	parse_map_content(&map);
	parse_parenting(&map);
	g_max_distance = nbr_len(map.room_list->size, 10);
	return (map);
}
