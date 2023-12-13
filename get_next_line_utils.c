/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:17:22 by vzuccare          #+#    #+#             */
/*   Updated: 2023/12/13 15:17:14 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	len_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strchr( const char *string, int searchedChar )
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)searchedChar)
			return ((char *)&string[i]);
		i++;
	}
	if (string[i] == (char)searchedChar)
		return ((char *)&string[i]);
	if (searchedChar == '\0')
		return ((char *)&string[i]);
	return (NULL);
}

char	*ft_strjoin_n(char *s1, char *s2)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	size = ft_strlen(s1) + len_line((char *)s2) + 1;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	i = -1;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	i = -1;
	while (s2[++i] && s2[i] != '\n')
		str[ft_strlen(s1) + i] = s2[i];
	if (s2[i] == '\n')
	{
		str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str[ft_strlen(s1) + i] = '\0';
	if (s1)
		free(s1);
	return (str);
}
