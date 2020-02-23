/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:31:51 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 22:10:38 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

BOOL			is_only_compose(char *src, char c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (src[i] != c)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int		get_next_line_result(char **line, char **saved, int result)
{
	if (*line != NULL)
		free(*line);
	if (ft_strlen(*saved) == 0)
	{
		*line = NULL;
		return (0);
	}
	*line = ft_strcut(saved, '\n');
	return (ft_strlen(*line) + ft_strlen(*saved) + result);
}

static int		handle_quit_get_next_line(char **saved_line, char **line)
{
	if (*saved_line != NULL)
		free(*saved_line);
	*saved_line = NULL;
	if (*line != NULL)
		free(*line);
	*line = NULL;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			result;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	static char	*saved[MAX_FD];

	if (fd == 1 || fd == 2 || fd >= MAX_FD)
		return (-1);
	result = 1;
	while (ft_strcchr(saved[fd], '\n') <= 0)
	{
		result = read(fd, buff, BUFF_SIZE);
		if (result == 0)
		{
			free(saved[fd]);
			break ;
		}
		buff[result] = '\0';
		if (is_only_compose(buff, '\0', BUFF_SIZE) == TRUE)
			return (handle_quit_get_next_line(&(saved[fd]), line));
		tmp = saved[fd];
		saved[fd] = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (get_next_line_result(line, &(saved[fd]), result));
}
