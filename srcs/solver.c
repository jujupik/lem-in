/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 17:12:21 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

BOOL		everyone_arrived(t_map *map, t_ant *anthill)
{
	size_t	i;
	t_ant	*ant;

	i = 0;
	while ((int)(i) < map->nb_fourmis)
	{
		ant = &(anthill[i]);
		if (ant->arrived == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_path		*find_send_path(t_list *paths)
{
	t_path	*tmp_path;

	tmp_path = get_shorter_send_path(paths);
	if (tmp_path != NULL)
	{
		tmp_path->send++;
		return (tmp_path);
	}
	return (NULL);
}

static void	create_anthill(t_map *map, t_list *paths, t_ant *anthill)
{
	size_t	i;

	i = 0;
	while ((int)(i) < map->nb_fourmis)
	{
		anthill[i] = create_ant(i, find_send_path(paths));
		i++;
	}
}

void		print_ant_output(t_map *map, t_list *paths, BOOL verbose)
{
	size_t	i;
	size_t	j;
	t_ant	*anthill;

	anthill = malloc(sizeof(t_ant) * map->nb_fourmis);
	if (anthill == NULL)
		error_exit(1, "Can't malloc an array of anthill");
	create_anthill(map, paths, anthill);
	j = 0;
	while (everyone_arrived(map, anthill) == FALSE)
	{
		if (j != 0)
			ft_printf("\n");
		j++;
		i = 0;
		while ((int)(i) < map->nb_fourmis)
		{
			move_ant(&(anthill[i]));
			i++;
		}
		if (everyone_arrived(map, anthill) == FALSE)
			print_anthill(anthill, map, verbose, j);
	}
	ft_printf("\n");
	free(anthill);
}
