/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_int_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:57:37 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/30 20:57:41 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

t_int_array	create_int_array(int *base_array, int base_size)
{
	t_int_array result;

	result.size = 0;
	result.content = NULL;
	set_int_array(&result, base_array, base_size);
	return (result);
}

t_int_array	*malloc_int_array(int *base_array, int base_size)
{
	t_int_array	*result;

	result = (t_int_array *)malloc(sizeof(t_int_array));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_int_array");
	*result = create_int_array(base_array, base_size);
	return (result);
}

void		destroy_int_array(t_int_array to_destroy)
{
	if (to_destroy.content != NULL)
		free(to_destroy.content);
}

void		free_int_array(t_int_array *to_free)
{
	destroy_int_array(*to_free);
	free(to_free);
}

void		set_int_array(t_int_array *array, int *base_array, int base_size)
{
	int	i;

	if (array->content == NULL || array->size != base_size)
	{
		destroy_int_array(*array);
		array->content = malloc(sizeof(int) * base_size);
		if (array->content == NULL)
			error_exit(0, "Can't malloc a int * in int_array");
		array->size = base_size;
	}
	i = 0;
	while (i < base_size)
	{
		array->content[i] = base_array[i];
		i++;
	}
}
