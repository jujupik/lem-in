#include "lem_in.h"

static void		parse_fourmis(t_map *map)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) && line_is_commentary(line) == TRUE)
	{
		//
	}
	if (line == NULL || ft_strisdigit(line) == FALSE)
		error_exit(1, "no fourmis line");
	map->nb_fourmis = ft_atoi(line);
	free(line);
}

static void		parse_link(t_map *map, char *line, BOOL *end)
{
	t_room *room_a;
	t_room *room_b;
	char **tab;

	if (line_is_link(line) == TRUE)
	{
		tab = ft_strsplit(line, '-');
		room_a = search_room(map, tab[0]);
		room_b = search_room(map, tab[1]);
		add_room_link(room_a, room_b);
	}
	else if (line_is_commentary(line) == FALSE)
	{
		*end = TRUE;
	}
}

static void		parse_room(t_map *map, char *line)
{
	static t_room_state state = normal;

	if (line_is_command(line) == TRUE)
	{
		if (ft_strcmp(line, "##start") == 0)
			state = start;
		if (ft_strcmp(line, "##end") == 0)
			state = end;
	}
	if (line_is_room(line) == TRUE)
		add_room(map, line, &state);
}

static void		parse_map_content(t_map *map)
{
	char *line;
	BOOL found;
	BOOL end;

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
	}
	free(line);
}

t_map			parse_map()
{
	t_map map;

	map = create_map();
	parse_fourmis(&map);
	parse_map_content(&map);
	print_map(&map);
	return (map);
}
