/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:09:50 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 14:09:52 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*calc_next_room(t_room *actual)
{
	t_room	*next;
	size_t	j;
	t_room	*tmp;

	next = NULL;
	j = 0;
	while (j < actual->links->size) //tant que j plus petit que le nb de chemin de actual
	{
		tmp = t_ptr_room_list_at(actual->links, j); //tmp room actuelle
		if ((next == NULL || next->distance > tmp->distance) &&
			(tmp->distance < actual->distance) && tmp->occuped == FALSE) //si la room precedente a une distance plus grande que l'actuelle
			next = tmp;
		j++;
	}
	return (next); //on renvoi la room avec la plus petite distance par rapport a actual
}

t_path			calc_path(t_map *map, t_room *departure) //map et depart
{
	size_t			i;
	t_ptr_room_list	result;
	t_room			*actual;
	t_room			*next;

	result = create_ptr_room_list(map->room_list->size); //create lst
	t_ptr_room_list_add(&result, departure); //on passe la room depart
	i = 0;
	while (i < result.size)
	{
		actual = t_ptr_room_list_at(&result, i); //la room
		if (actual->distance != 0) //tant qu'on est pas sur la room start
		{
			next = calc_next_room(actual); //next la room avec la plus petite distance par rapport a actual
			if (next == NULL)
			{
				destroy_ptr_room_list(result);
				return (create_ptr_room_list(map->room_list->size));
			}
			t_ptr_room_list_add(&result, next); //ajoute next au path result
			next->occuped = (next->distance != 0 ? TRUE : FALSE); //on le set a occuped
		}
		i++;
	}
	return (result);
}

void			print_path(t_path *path, char *name)
{
	size_t i;
	t_room *tmp;

	i = 0;
	ft_printf("%s :\n", name);
	if (path == NULL || path->size == 0)
	{
		ft_printf("No path");
	}
	else
	{
		while (i < path->size)
		{
			tmp = t_ptr_room_list_at(path, i);
			if (i != 0)
				ft_printf("-");
			ft_printf("%s", tmp->name);
			i++;
		}
	}
	ft_printf("\n");
}
