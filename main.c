/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:50:40 by vzuccare          #+#    #+#             */
/*   Updated: 2023/12/01 14:59:08 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open the file.\n");
		return 1;
	}
	get_next_line(fd);
	return 0;
}
