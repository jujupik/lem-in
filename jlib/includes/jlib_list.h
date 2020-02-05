/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:40:15 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/04 23:39:29 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JLIB_LIST_H
# define JLIB_LIST_H

typedef struct	s_list
{
	void		***content;
	size_t		size;
	size_t		max_size;
	size_t		nb_line;
	size_t		push_size;
}				t_list;

t_list		create_list(size_t p_push_size);
t_list		*malloc_list(size_t p_push_size);
void		destroy_list(t_list to_destroy);
void		free_list(t_list *to_free);
t_vector2	list_calc_index_coord(t_list *list, size_t index);
void		list_push_back(t_list *list, void *to_add);
void		*list_at(t_list *list, size_t index);
void		**list_get(t_list *list, size_t index);

#endif
