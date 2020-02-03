/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_room.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:55:10 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 01:15:46 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_ROOM_H
# define LEM_IN_ROOM_H

typedef enum		e_room_state
{
	normal = 0,
	start = 1,
	end = 2
}					t_room_state;

char				*status_str(t_room_state status);

typedef struct		s_room
{
	char					*name;
	int						x;
	int						y;
	t_room_state			status;
	struct s_room_list		*links;
	struct s_room_list		*self_links;
	long long				distance;
	int						nb_use;
	BOOL					occuped;
	struct s_fourmis		*fourmis;
}					t_room;

t_room				create_room(char *p_name, t_room_state p_status, int x,
						int y);
t_room				*malloc_room(char *p_name, t_room_state p_status, int x,
						int y);
void				destroy_room(t_room to_destroy);
void				free_room(t_room *to_free);
void				room_add_link(t_room *a, t_room *b);
void				print_room(t_room *room, size_t index);

typedef struct		s_room_list
{
	t_room			**content;
	size_t			size;
	size_t			max_size;
	size_t			push_size;
}					t_room_list;

t_room_list			create_room_list(size_t p_push_size);
t_room_list			*malloc_room_list(size_t p_push_size);
void				destroy_room_list(t_room_list list);
void				free_room_list(t_room_list *list);
void				t_room_list_add(t_room_list *list, t_room *to_add);
t_room				*t_room_list_at(t_room_list *list, size_t index);
t_room				**t_room_list_get(t_room_list *list, size_t index);
void				print_room_list(t_room_list *room);

#endif
