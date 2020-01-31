/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:50:24 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/31 16:50:25 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

BOOL	line_is_commentary(char *line) //commentaire commence par #
{
	if (line[0] == '#' && line[1] != '#')
		return (TRUE);
	return (FALSE);
}

BOOL	line_is_command(char *line) //commande commence par ##
{
	if (line[0] == '#' && line[1] == '#')
		return (TRUE);
	return (FALSE);
}

BOOL	line_is_room(char *line) //regarde si format room correct
{
	char	**tab;
	size_t	len;

	if (line_is_commentary(line) == TRUE || line_is_command(line) == TRUE) //si la ligne est un commentaire ou une commande return FALSE
		return (FALSE);
	tab = ft_strsplit(line, ' '); //on split selon les espace pour recup les 3 partie [0]le nom [1]coordonne [2]coordonne
	len = ft_tab_len(tab);
	ft_tab_free(tab);
	return (len == 3 ? TRUE : FALSE);
}

BOOL	line_is_link(char *line) //regarde si format chemin correct
{
	char	**tab;
	size_t	len;

	if (line_is_commentary(line) == TRUE || line_is_command(line) == TRUE)
		return (FALSE);
	tab = ft_strsplit(line, '-');
	len = ft_tab_len(tab);
	ft_tab_free(tab);
	return (len == 2 ? TRUE : FALSE);
}

BOOL	is_name_valid(t_room_list *list, char *name) //cas d'erreur des noms de room valide
{
	size_t	i;
	char	*to_test;

	if (name[0] == 'L' ||
		ft_strcchr(name, ' ') == 1 || ft_strcchr(name, '-') == 1)
		return (FALSE);
	i = 0;
	while (i < list->size)
	{
		to_test = t_room_list_at(list, i).name;
		if (ft_strcmp(to_test, name) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
