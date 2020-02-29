/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:24 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 13:46:54 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

BOOL	line_is_commentary(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (TRUE);
	return (FALSE);
}

BOOL	line_is_command(char *line)
{
	if (line[0] == '#' && line[1] == '#')
		return (TRUE);
	return (FALSE);
}

BOOL	line_is_room(char *line)
{
	char	**tab;
	size_t	len;

	if (line_is_commentary(line) == TRUE || line_is_command(line) == TRUE)
		return (FALSE);
	tab = ft_strsplit(line, ' ');
	len = ft_tab_len(tab);
	ft_tab_ft_free(tab);
	return (len == 3 ? TRUE : FALSE);
}

BOOL	line_is_link(char *line)
{
	char	**tab;
	size_t	len;

	if (line_is_commentary(line) == TRUE || line_is_command(line) == TRUE)
		return (FALSE);
	tab = ft_strsplit(line, '-');
	len = ft_tab_len(tab);
	ft_tab_ft_free(tab);
	return (len == 2 ? TRUE : FALSE);
}

BOOL	is_name_valid(t_list *list, char *name)
{
	size_t	i;
	char	*to_test;

	if (name[0] == 'L' ||
		ft_strcchr(name, ' ') == 1 || ft_strcchr(name, '-') == 1)
		return (FALSE);
	i = 0;
	while (i < list->size)
	{
		to_test = ((t_room *)(list_at(list, i)))->name;
		if (ft_strcmp(to_test, name) == TRUE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
