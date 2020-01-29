#ifndef LEM_IN_MAP_H
#define LEM_IN_MAP_H

typedef struct	s_map
{
	int nb_fourmis;
	t_room_list *room_list;
	t_room *start;
	t_room *end;
}				t_map;

t_map create_map();
t_map *malloc_map();
void destroy_map(t_map to_destroy);
void free_map(t_map *to_free);

void parse_map(t_map *map);

void print_map(t_map *map);

#endif
