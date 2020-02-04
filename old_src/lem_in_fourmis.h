/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_fourmis.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:55:20 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 08:24:09 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_FOURMIS_H
# define LEM_IN_FOURMIS_H

typedef struct	s_fourmis
{
	size_t		name;
	int			path_index;
	int			room_index;
	BOOL		arrived;
}				t_fourmis;

t_fourmis		create_fourmis(size_t p_name, int p_path, int p_room);
t_fourmis		*malloc_fourmis(size_t p_name, int p_path, int p_room);
void			destroy_fourmis(t_fourmis to_destroy);
void			free_fourmis(t_fourmis *to_free);
void			print_fourmis(t_solution *solution, t_fourmis *fourmis);

#endif
