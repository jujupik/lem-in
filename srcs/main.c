/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 20:06:57 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
