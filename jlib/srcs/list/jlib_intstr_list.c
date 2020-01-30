/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_str_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:49:32 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/24 16:49:35 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

t_intstr_list		create_intstr_list(size_t p_push_size)
{
	t_intstr_list result;

	result.push_size = p_push_size;
	result.max_size = result.push_size;
	result.content = malloc(sizeof(t_int_array) * result.max_size);
	if (result.content == NULL)
		error_exit(-2, "can't malloc str list");
	result.size = 0;
	return (result);
}

t_intstr_list		*malloc_intstr_array(size_t p_push_size)
{
	t_intstr_list	*result;

	result = (t_intstr_list *)malloc(sizeof(t_intstr_list));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_intstr_list");
	*result = create_intstr_list(p_push_size);
	return (result);
}

void				destroy_intstr_list(t_intstr_list to_destroy)
{
	free(to_destroy.content);
}

void				free_intstr_list(t_intstr_list *to_free)
{
	destroy_intstr_list(*to_free);
	free(to_free);
}
