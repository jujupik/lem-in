/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_path.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:55:06 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/02 21:31:20 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_PATH_H
# define LEM_IN_PATH_H

typedef struct s_path
{
	t_ptr_room_list *path;
	int				count;
}				t_path;

t_path			create_path(t_ptr_room_list *p_path);
t_path			*malloc_path(t_ptr_room_list *p_path);
void 			destroy_path(t_path to_destroy);
void 			free_path(t_path *to_free);
void			copy_path(t_path *dest, t_path *src);

typedef struct	s_path_list
{
	t_path		**content;
	size_t		size;
	size_t		max_size;
	size_t		push_size;
}				t_path_list;

t_path_list		create_path_list(size_t p_push_size);
t_path_list		*malloc_path_list(size_t p_push_size);
void			destroy_path_list(t_path_list list);
void			free_path_list(t_path_list *list);
void			t_path_list_add(t_path_list *list, t_path *to_add);
t_path			*t_path_list_at(t_path_list *list, size_t index);
t_path			**t_path_list_get(t_path_list *list, size_t index);
void			calc_room_distance(t_room *actual, size_t parent_distance);
void			calc_distance(t_map *map);
t_path			*calc_path(t_map *map, t_room *departure);
t_path			*calc_mono_path(t_map *map);
void			print_path(t_path *path, char *name);
void			reverse_path(t_path *path);
void			copy_path_list(t_path_list *dest, t_path_list *src);
void			clear_path_list(t_path_list *path);
#endif
