/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:55:20 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/02 23:38:48 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "lem_in_includes.h"

# include "lem_in_room.h"
# include "lem_in_map.h"
# include "lem_in_path.h"
# include "lem_in_solution.h"
# include "lem_in_fourmis.h"

BOOL			line_is_commentary(char *line);
BOOL			line_is_command(char *line);
BOOL			line_is_room(char *line);
BOOL			line_is_link(char *line);
BOOL			is_name_valid(t_room_list *list, char *name);
void			print_int_solution(int *value, int nb_value);
t_solution		solver(t_map *map);
void			print_out_map(t_map *map);

#endif
