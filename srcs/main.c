/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 19:29:14 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

BOOL		parse_options(int argc, char **argv, BOOL *options)
{
	int		i;

	i = 1;
	while (i < argc)
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
		else if (ft_strcmp(argv[i], "--leaks") == TRUE ||
			ft_strcmp(argv[i], "-l") == TRUE)
			options[LEAKS] = TRUE;
		else if (ft_strcmp(argv[i], "--checker") == TRUE ||
			ft_strcmp(argv[i], "-c") == TRUE)
			options[CHECKER] = TRUE;
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void		print_usage(void)
{
	static int space = 25;

	ft_printf("Usage : ./lem-in [--option] < [Map a tester]\n");
	ft_printf("Options :\n");
	ft_printf("%*s -> Print the paths found \
by lem-in, nb turn to run the map\n", space, "--verbose (-v)");
	ft_printf("%*s -> Print only the paths and total \
number of turn (Usefull when many ant on the hill)\n", space, "--simple (-s)");
	ft_printf("%*s -> Print the map after the calculation of paths\n",
	space, "--map (-m)");
	ft_printf("%*s -> Print only the active room of the map after \
calculation\n", space, "--map-active (-m2)");
	ft_printf("%*s -> Print leaks at the end of the program\n",
	space, "--leaks (-l)");
	ft_printf("%*s -> Check room used only one time\n",
	space, "--checker (-c)");
	exit(0);
}

BOOL		had_options(BOOL *options)
{
	size_t i;

	i = 0;
	while (i < NB_OPTION)
	{
		if (options[i] == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int			main(int argc, char **argv)
{
	BOOL	options[NB_OPTION];
	size_t	i;

	g_debug = 1;
	i = 0;
	while (i < NB_OPTION)
	{
		options[i] = FALSE;
		i++;
	}
	if (argc >= 2)
	{
		if (parse_options(argc, argv, options) == FALSE ||
			had_options(options) == FALSE)
			print_usage();
	}
	lem_in(options);
	if (options[LEAKS] == TRUE)
	{
		ft_printf("\n");
		ft_get_leaks("At the end of program");
	}
	return (0);
}
