/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:17:38 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 16:34:23 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

t_list	create_list(size_t p_push_size)
{
	t_list result;

	result.content = NULL;
	result.size = 0;
	result.push_size = p_push_size;
	result.nb_line = 0;
	result.max_size = 0;
	return (result);
}

t_list	*malloc_list(size_t p_push_size)
{
	t_list	*result;

	result = (t_list *)ft_malloc(sizeof(t_list));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_list");
	*result = create_list(p_push_size);
	return (result);
}

void	destroy_list(t_list to_destroy, t_destroy_funct funct)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < to_destroy.nb_line)
	{
		j = 0;
		while (j < to_destroy.push_size)
		{
			if (funct != NULL)
				funct(to_destroy.content[i][j]);
			j++;
		}
		ft_free(to_destroy.content[i]);
		i++;
	}
	if (to_destroy.content != NULL)
		ft_free(to_destroy.content);
}

void	free_list(t_list *to_free, t_destroy_funct funct)
{
	destroy_list(*to_free, funct);
	ft_free(to_free);
}
