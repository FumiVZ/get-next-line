/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:17:22 by vzuccare          #+#    #+#             */
/*   Updated: 2023/12/01 14:21:57 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strlcat_line(char *dst, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[j] && src[j] != '\n')
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[j] && src[j] != '\n')
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst);
}
