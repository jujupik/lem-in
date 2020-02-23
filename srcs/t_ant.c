/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ant.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 17:11:04 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	create_ant(size_t p_name, t_path *p_path)
{
	t_ant	result;

	result.name = p_name;
	result.index = 0;
	result.path = p_path;
	result.arrived = FALSE;
	return (result);
}

void	move_ant(t_ant *ant)
{
	t_room	*room;
	t_room	*next_room;

	room = list_at(ant->path->road, ant->index);
	if (room->state == end)
	{
		ant->arrived = TRUE;
		return ;
	}
	next_room = list_at(ant->path->road, ant->index + 1);
	if (next_room->ant == NULL)
	{
		ant->index++;
		room->ant = NULL;
		if (next_room->state != end)
			next_room->ant = ant;
	}
}

BOOL	print_ant(t_ant *ant, BOOL verbose)
{
	t_room	*room;
	t_room	*prev_room;

	room = list_at(ant->path->road, ant->index);
	if (room->state != start && ant->arrived == FALSE)
	{
		if (verbose == TRUE)
		{
			prev_room = list_at(ant->path->road, ant->index - 1);
			ft_printf("L%u %s->%s", ant->name, prev_room->name, room->name);
		}
		else
			ft_printf("L%u-%s", ant->name, room->name);
		return (TRUE);
	}
	return (FALSE);
}

void	print_anthill(t_ant *anthill, t_map *map, BOOL verbose, size_t nb_turn)
{
	size_t	i;
	int		len;
	t_ant	*ant;
	BOOL	first_ant;

	i = 0;
	first_ant = FALSE;
	if (verbose == TRUE)
	{
		len = nbr_len(map->nb_fourmis, 10);
		ft_printf("Turn [%*u] : ", len, nb_turn);
	}
	while ((int)(i) < map->nb_fourmis)
	{
		ant = &(anthill[i]);
		if (first_ant == TRUE)
			ft_printf("%s", (verbose == TRUE ? "  /  " : " "));
		first_ant = print_ant(ant, verbose);
		i++;
	}
}
