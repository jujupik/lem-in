/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:55:20 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 18:35:08 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "lem_in_includes.h"

# define NB_OPTION 4
# define VERBOSE 0
# define SIMPLE 1
# define MAP 2
# define LEAKS 3

extern size_t		g_name_max_len;
extern size_t		g_max_distance;

typedef struct		s_ant
{
	size_t			name;
	size_t			index;
	BOOL			arrived;
	struct s_link	*actual;
	struct s_path	*path;
}					t_ant;

t_ant				create_ant(size_t p_name, struct s_path *p_path);
void				move_ant(t_ant *ant);
BOOL				print_ant(t_ant *ant, BOOL verbose, BOOL first_ant);

typedef enum		e_room_state
{
	normal = 0,
	start = 1,
	end = 2
}					t_room_state;

char				*state_str(t_room_state state);

typedef struct		s_room
{
	char			*name;
	t_room_state	state;
	BOOL			active;
	size_t			distance;
	int				x;
	int				y;
	t_list			*links;
	t_list			*my_link;
	struct s_room	*previous;
}					t_room;

t_room				create_room(char *p_name, t_room_state p_state, int x,
									int y);
t_room				*malloc_room(char *p_name, t_room_state p_state, int x,
									int y);
void				destroy_room(t_room to_destroy);
void				free_room(t_room *to_free);
void				print_room(t_room *room);
void				add_room_link(t_room *parent, t_room *children);
int					room_flow_total(t_room *room);
int					room_flow_parent(t_room *room);
int					room_flow_children(t_room *room);

typedef struct		s_link
{
	t_room			*parent;
	t_room			*children;
	t_room			*actual_parent;
	t_ant			*ant;
	int				flow;
}					t_link;

t_link				create_link(t_room *p_parent, t_room *p_children);
t_link				*malloc_link(t_room *p_parent, t_room *p_children);
void				destroy_link(t_link to_destroy);
void				free_link(t_link *to_free);
void				print_link(t_room *room, t_link *link);
void				swap_link(t_link *link);

typedef struct		s_path
{
	t_list			*road;
	size_t			count;
	size_t			send;
}					t_path;

t_path				create_path();
t_path				*malloc_path();
void				destroy_path(t_path to_destroy);
void				free_path(t_path *to_free);
void				add_room_to_path(t_path *path, t_room *room);
void				print_path(t_path *path);

typedef struct		s_map
{
	t_list			*map_string;
	int				nb_fourmis;
	t_list			*room_list;
	t_room			*start;
	t_room			*end;
}					t_map;

t_map				create_map(void);
t_map				*malloc_map(void);
void				destroy_map(t_map to_destroy);
void				free_map(t_map *to_free);
void				print_map(t_map *map);
void				print_map_strange(t_map *map);
void				set_map_room(t_map *map, t_room *room);
void				add_room(t_map *map, char *line, t_room_state *state);
t_room				*search_room(t_map *map, char *room_name);
t_map				parse_map();
void				parse_parenting(t_map *map);

BOOL				line_is_commentary(char *line);
BOOL				line_is_command(char *line);
BOOL				line_is_room(char *line);
BOOL				line_is_link(char *line);
BOOL				is_name_valid(t_list *list, char *name);

void				reset_distance(t_map *map);
void				reverse_path(t_path *path);
t_link				*search_link(t_room *actual, t_room *dest);
void				active_path(t_path *path);
void				desactive_path(t_path *path);

void				calc_distance(t_room *room);
void				calc_complete_distance(t_room *room, size_t parent_dist);
t_path				*calc_path(t_map *map);
t_room				*get_next_room(t_room *room);
t_room				*find_next_room(t_room *room);
t_path				*get_path(t_room *room);
t_list				*parse_path(t_map *map);
t_path				*get_shorter_path(t_list *paths);
t_path				*get_shorter_send_path(t_list *paths);
t_path				*get_longuest_path(t_list *paths);
void				prepare_path(t_map *map, t_list *paths);
t_list				*find_all_path(t_map *map);
size_t				solution_note(t_list *paths);

void				print_anthill(t_ant *anthill, t_map *map, BOOL verbose,
									size_t nb_turn);
void				print_ant_output(t_map *map, t_list *paths, BOOL verbose);

void				tmp_free_room(void *room);
void				tmp_free_path(void *path);
void				tmp_free_link(void *link);

void				lem_in(BOOL *options);

#endif
