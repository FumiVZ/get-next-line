/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:50:02 by vzuccare          #+#    #+#             */
/*   Updated: 2024/01/09 18:16:35 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "get_next_line.h"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

void	full_clean(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		str[i++] = '\0';
}

void	clear_until_n(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i])
		str[j++] = str[i++];
	str[j] = '\0';
}

char	*read_and_process_lines(int fd, char *buff, char *stash, int ret)
{
	while (ret)
	{
		if (ft_strlen(stash) == 0)
		{
			ret = read(fd, stash, BUFFER_SIZE);
			if (ret < 0)
			{
				free(buff);
				return (NULL);
			}
			else if (ret == 0 && ft_strlen(stash) == 0)
				return (buff);
			else if (ret == 0 && ft_strlen(stash) != 0)
				return (ft_strjoin_n(buff, stash));
			if (ret != 0)
				stash[ret] = '\0';
		}
		buff = ft_strjoin_n(buff, stash);
		if (!buff)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			break ;
		clear_until_n(stash);
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*buff;

	if (read(fd, stash, 0))
	{
		if (strlen(stash) != 0)
			full_clean(stash);
		return (NULL);
	}
	clear_until_n(stash);
	buff = NULL;
	buff = read_and_process_lines(fd, buff, stash, 1);
	if (!buff)
	{
		if (strlen(stash) != 0)
			full_clean(stash);
		return (NULL);
	}
	return (buff);
}
