/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:38:27 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 16:47:54 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

void	ft_get_leaks(char *prog_name, char *msg)
{
	char	*command;
	char	*tmp;

	tmp = ft_strdup("leaks ");
	command = ft_strjoin(tmp, prog_name);
	free(tmp);
	tmp = command;
	command = ft_strjoin(tmp, " | grep 'total leaked bytes'");
	free(tmp);
	system(command);
	ft_putstr(msg);
	ft_putchar('\n');
	ft_putchar('\n');
	free(command);
}

void	ft_get_leaks_total(char *prog_name)
{
	char	*command;
	char	*tmp;

	tmp = ft_strdup("leaks ");
	command = ft_strjoin(tmp, prog_name);
	free(tmp);
	system(command);
	free(command);
}
