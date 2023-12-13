/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:52:08 by vzuccare          #+#    #+#             */
/*   Updated: 2023/12/13 14:18:01 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup_line(char *dst, char *src);
char	*ft_strjoin_n(char *s1, char *s2);
char	*ft_strchr( const char *string, int searchedChar );
char	*strjoin_free(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	full_clean(char *str);

#endif