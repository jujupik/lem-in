/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:43:55 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/29 13:43:57 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "lem_in_includes.h"

# include "lem_in_room.h"
# include "lem_in_map.h"
# include "lem_in_path.h"

BOOL line_is_commentary(char *line);
BOOL line_is_command(char *line);
BOOL line_is_room(char *line);
BOOL line_is_link(char *line);
BOOL is_name_valid(t_room_list *list, char *name);
void print_solution(int *value, int nb_value);

#endif
