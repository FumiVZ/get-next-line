/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:50:02 by vzuccare          #+#    #+#             */
/*   Updated: 2023/12/01 16:00:06 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_stash(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (stash[i])
	{
		if (stash[i++] == '\n')
		{
			ft_strlcat_line(line, stash);
			return (line);
		}
	}
	return (line);
}

void	clear_stash(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	while (stash[j] && stash[j] != '\n')
		j++;
	str = malloc(sizeof(char) * (i - j + 1));
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		stash[j++] = stash[i++];
	stash[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			i;

	line = NULL;
	i = 0;
	while (stash[i] != '\n')
	{
		read(fd, stash, BUFFER_SIZE);
		while (i < BUFFER_SIZE && stash[i] != '\n')
			i++;
	}
	line = ft_strlcat_line(line, stash);
	clear_stash(stash);
	return (line);
}
