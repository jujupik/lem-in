/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_solution_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:49 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 16:50:49 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_solution(t_solution *solution)
{
	t_path		tmp;
	t_ptr_room	room;
	size_t		i;

	i = 0;
	while (i < solution->paths.size)
	{
		tmp = t_path_list_at(&(solution->paths), i);
		room = t_ptr_room_list_at(&tmp, 0);
		print_path(&tmp, room->name);
		i++;
	}
	ft_printf("\n\n");
}

void	calc_solution_note(t_solution *solution)
{
	t_path	tmp;
	size_t	tmp_len;
	float	len;
	size_t	i;

	len = 0;
	i = 0;
	while (i < solution->paths.size)
	{
		tmp = t_path_list_at(&(solution->paths), i);
		tmp_len = tmp.size;
		if (tmp_len > len)
			len = tmp_len;
		i++;
	}
	solution->note = len / solution->paths.size;
}

void	copy_solution(t_solution *dest, t_solution *src)
{
	size_t	i;

	i = 0;
	dest->paths.size = 0;
	while (i < src->paths.size)
	{
		t_path_list_add(&(dest->paths), t_path_list_at(&(src->paths), i));
		i++;
	}
	dest->note = src->note;
}

void	reverse_solution(t_solution *solution)
{
	size_t	i;
	t_path	*path;

	i = 0;
	while (i < solution->paths.size)
	{
		path = t_path_list_get(&(solution->paths), i);
		reverse_path(path);
		i++;
	}
}
