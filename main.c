/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:50:40 by vzuccare          #+#    #+#             */
/*   Updated: 2023/12/13 18:18:57 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	size_t i = 0;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open the file.\n");
		return 1;
	}
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
		i++;
	}
	return 0;
	
}
