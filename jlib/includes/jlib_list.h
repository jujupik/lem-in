/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:40:15 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/24 17:40:17 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JLIB_LIST_H
# define JLIB_LIST_H

typedef struct	s_vector2_list
{
	t_vector2	*content;
	size_t		size;
	size_t		max_size;
	size_t		push_size;
}				t_vector2_list;

t_vector2_list	create_vector2_list(size_t p_push_size);
void			free_vector2_list(t_vector2_list list);
void			t_vector2_list_add(t_vector2_list *list, t_vector2 to_add);
t_vector2		t_vector2_list_at(t_vector2_list *list, size_t index);

typedef char*	t_str;

typedef struct	s_str_list
{
	t_str		*content;
	size_t		size;
	size_t		max_size;
	size_t		push_size;
}				t_str_list;

t_str_list		create_str_list(size_t p_push_size);
void			free_str_list(t_str_list list);
void			t_str_list_add(t_str_list *list, t_str to_add);
t_str			t_str_list_at(t_str_list *list, size_t index);

typedef struct	s_int_array
{
	int			*content;
	size_t		size;
}				t_int_array;

t_int_array		create_int_array(int *base_array, int base_size);
t_int_array		*malloc_int_array(int *base_array, int base_size);
void			destroy_int_array(t_int_array to_destroy);
void			free_int_array(t_int_array *to_free);
void			set_int_array(t_int_array *array, int *base_array,
					int base_size);

typedef struct	s_intstr_list
{
	t_int_array	*content;
	size_t		size;
	size_t		max_size;
	size_t		push_size;
}				t_intstr_list;

t_intstr_list	create_intstr_list(size_t p_push_size);
t_intstr_list	*malloc_intstr_list(size_t p_push_size);
void			destroy_intstr_list(t_intstr_list to_destroy);
void			free_intstr_list(t_intstr_list *to_free);
void			t_intstr_list_add(t_intstr_list *list, t_int_array to_add);
t_int_array		t_intstr_list_at(t_intstr_list *list, size_t index);

#endif
