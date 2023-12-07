/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:17:22 by vzuccare          #+#    #+#             */
/*   Updated: 2023/12/07 13:23:02 by vzuccare         ###   ########lyon.fr   */
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

char	*ft_strdup_line(char *dst, char *src)
{
	size_t		j;

	j = 0;
	while (src[j] && src[j] != '\n')
		j++;
	dst = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (src[j] && src[j] != '\n')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	if (src)
		free(src);
	return (dst);
}
char	*ft_strchr( const char *string, int searchedChar )
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)searchedChar)
			return ((char *)&string[i + 1]);
		i++;
	}
	if (string[i] == (char)searchedChar)
		return ((char *)&string[i + 1]);
	if (searchedChar == '\0')
		return ((char *)&string[i + 1]);
	return (NULL);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str[ft_strlen(s1) + i] = '\0';
	return (str);
}