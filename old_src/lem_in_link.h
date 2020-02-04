/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_link.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:55:20 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/03 08:18:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LINK_H
# define LEM_IN_LINK_H

typedef struct	s_link
{
	struct s_room *parent;
	struct s_room *children;
	int			flow;
	int			residual_flow;
}				t_link;

t_link		create_link(struct s_room *a, struct s_room *b);
t_link		*malloc_link(size_t p_name, int p_path, int p_room);
void		destroy_link(t_link to_destroy);
void		free_link(t_link *to_free);
void		print_link(t_solution *solution, t_link *link);

#endif
