/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_solution_note.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:49 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/01 00:18:29 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t get_shorter_path(t_solution *solution)
{

}

void place_fourmis(t_map *map, size_t nb_path)
{
	size_t	i;

	i = 0;
	while (i < map->nb_fourmis)
	{
		// 1) trouver le chemin le plus court actuel en comptant les autres fourmis
		// 2) ajouter 1 a nb_turn_to_end de ce chemin
		i++;
	}
}

void	calc_solution_note(t_map *map, t_solution *solution)
{
	int		*nb_fourmi_per_chemin;
	t_path	*tmp;
	size_t	i;

	nb_fourmi_per_chemin = (int *)malloc(sizeof(int) * solution->paths.size);
	i = 0;
	while (i < solution->paths.size)
	{
		tmp = t_path_list_get(&(solution->paths), i);
		nb_fourmi_per_chemin[i] = tmp->size;
		i++;
	}
	solution->note = 1;
}
