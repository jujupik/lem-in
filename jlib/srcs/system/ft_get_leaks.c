/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:38:27 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 19:25:52 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

BOOL g_debug = FALSE;
t_chain *g_ptr_chain = NULL;

void	*ft_malloc(size_t size)
{
	static BOOL		grown = FALSE;
	static size_t	ptr_index = 0;
	t_address		*address;
	void			*result;
	void			*tmp_list;

	if (size == 0)
		return (NULL);
	result = malloc(size);
	if (grown == TRUE)
		return (result);
	grown = TRUE;
	address = malloc_address(ptr_index, result);
	if (g_debug == TRUE)
		address_get_trace(address);
	ptr_index++;
	if (g_ptr_chain == NULL)
		g_ptr_chain = malloc_chain(address);
	else
		chain_push_back(g_ptr_chain, address);
	grown = FALSE;
	return (result);
}

void	ft_free(void *to_free)
{
	chain_erase(&g_ptr_chain, to_free);
	free(to_free);
}

void	ft_get_leaks(char *msg)
{
	t_address	*tmp;
	size_t		len;
	size_t		i;

	len = chain_len(g_ptr_chain);
	i = 0;
	while (i < len)
	{
		tmp = chain_at(g_ptr_chain, i);
		print_address(tmp);
		i++;
	}
	if (i == 0)
		ft_printf("No leaks\n");
	ft_printf("%s\n", msg);
}
