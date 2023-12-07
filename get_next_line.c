/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:50:02 by vzuccare          #+#    #+#             */
/*   Updated: 2023/12/07 13:20:13 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stash;
	char *buff;
	char *line;

	line = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!stash)
		stash = ft_strdup_line(stash, "");
    while (read(fd, buff, BUFFER_SIZE) > 0)
    {
        stash = ft_strjoin(stash, buff);
		if (!stash)
		{
			free(buff);
			return (NULL);
		}
        if (ft_strchr(buff, '\n'))
            break ;
    }
	free(buff);
    line = ft_strdup_line(line, stash);
    if (!line)
    {
        free(stash);
        return (NULL);
    }
	stash = ft_strchr(stash, '\n');
	return(line);
}
