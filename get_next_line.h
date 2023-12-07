/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:52:08 by vzuccare          #+#    #+#             */
/*   Updated: 2023/12/05 15:12:10 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup_line(char *dst, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr( const char *string, int searchedChar );

#endif