/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 17:06:07 by jrouchon         ###   ########.fr       */
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
		else if (ft_strcmp(argv[i], "--leaks") == TRUE ||
			ft_strcmp(argv[i], "-l") == TRUE)
			options[LEAKS] = TRUE;
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
	ft_printf("%*s -> Print leaks at the end of the program\n",
	space, "--leaks (-l)");
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

	options[0] = FALSE;
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
		ft_get_leaks_total("lem-in");
	}
	return (0);
}
