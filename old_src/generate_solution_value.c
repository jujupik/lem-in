/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_solution_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:41 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/02 19:01:23 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_int_solution(int *value, int nb_value)
{
	int	z;

	z = 0;
	ft_printf("Combinaison : ");
	if (nb_value == 0)
		ft_printf("No path");
	while (z < nb_value)
	{
		if (z != 0)
			ft_printf(" - ");
		ft_printf("%d", value[z]);
		z++;
	}
	ft_printf("\n");
}

static int	*create_value_list(int nb_value)
{
	int	*value;
	int	j;

	value = ft_int_str_new(nb_value);
	j = 0;
	while (j < nb_value)
	{
		value[j] = j;
		j++;
	}
	return (value);
}

void		generate_solution_value(t_intstr_list *list, int len, int nb_value)
{
	static int	*value = NULL;
	int			i;

	if (value == NULL)
		value = create_value_list(nb_value);
	if (len == nb_value)
		t_intstr_list_add(list, create_int_array(value, nb_value));
	else
	{
		i = len;
		while (i < nb_value)
		{
			ft_swap_int(&(value[len]), &(value[i]));
			generate_solution_value(list, len + 1, nb_value);
			ft_swap_int(&(value[len]), &(value[i]));
			i++;
		}
	}
}
