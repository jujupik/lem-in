/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 20:12:03 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static BOOL		parse_options1(int i, char **argv, BOOL *options)
{
	if (ft_strcmp(argv[i], "--verbose") == TRUE ||
		ft_strcmp(argv[i], "-v") == TRUE)
		options[VERBOSE] = TRUE;
	else if (ft_strcmp(argv[i], "--simple") == TRUE ||
		ft_strcmp(argv[i], "-s") == TRUE)
		options[SIMPLE] = TRUE;
	else if (ft_strcmp(argv[i], "--map") == TRUE ||
		ft_strcmp(argv[i], "-m") == TRUE)
		options[MAP] = TRUE;
	else if (ft_strcmp(argv[i], "--map-active") == TRUE ||
		ft_strcmp(argv[i], "-m2") == TRUE)
		options[MAP_ACTIVE] = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

static BOOL		parse_options2(int i, char **argv, BOOL *options)
{
	if (ft_strcmp(argv[i], "--leaks") == TRUE ||
		ft_strcmp(argv[i], "-l") == TRUE)
		options[LEAKS] = TRUE;
	else if (ft_strcmp(argv[i], "--checker") == TRUE ||
		ft_strcmp(argv[i], "-c") == TRUE)
		options[CHECKER] = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

BOOL			parse_options(int argc, char **argv, BOOL *options)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (parse_options1(i, argv, options) == FALSE &&
			parse_options2(i, argv, options) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
