/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:54:52 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 23:33:11 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_MAP_H
# define LEM_IN_MAP_H

typedef struct	s_map
{
	int					nb_fourmis;
	t_ptr_room_list		*room_list;
	t_room				*start;
	t_room				*end;
}				t_map;

t_map			create_map();
t_map			*malloc_map();
void			destroy_map(t_map to_destroy);
void			free_map(t_map *to_free);

void			parse_map(t_map *map);
void			parse_map_content(t_map *map);
void			parse_nb_fourmis(t_map *map);
void			parse_room(t_map *map, char *line, t_room_state *status);
void			parse_command(char *line, t_room_state *status);
t_room			*search_room(t_map *map, char *room_name);
void			parse_link(t_map *map, char *line, BOOL *utils);

void			draw_links(t_ptr_room_list *links);
void			print_map(t_map *map);
void			reset_map_occupation(t_map *map);

#endif
