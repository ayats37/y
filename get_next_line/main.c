/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:00:37 by taya              #+#    #+#             */
/*   Updated: 2024/10/26 00:53:21 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int main()
{
	char *line;
	ssize_t fd;
	
	fd = open("file1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error reading a file");
		return (1);
	}
	if ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}