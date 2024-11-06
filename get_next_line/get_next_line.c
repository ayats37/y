/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 03:55:55 by taya              #+#    #+#             */
/*   Updated: 2024/10/26 19:21:48 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

#define BUFFER_SIZE 5

char	*ft_read(int fd, char *buffer)
{
	ssize_t	bytes_read;
	char tmp[BUFFER_SIZE + 1];
	char *join_tmp;
	bytes_read = 1;
	if (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	}

	tmp[bytes_read] = '\0';
	join_tmp = ft_strjoin(buffer, tmp);
	return (join_tmp);
}

char	*ft_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	line = NULL;
	line = malloc((ft_strlen(buffer) + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save_leftover(char *buffer)
{
	char	*after_newline;
	char	*leftover;
	int		len_leftover;

	after_newline = ft_strchr(buffer, '\n');
	if (!after_newline)
	{
		free(buffer);
		return (NULL);
	}
	after_newline += 1;
	len_leftover = ft_strlen(after_newline);
	leftover = malloc((len_leftover + 1) * sizeof(char));
	if (!leftover)
	{
		free(buffer);
		return (NULL);
	}
	ft_strcpy(leftover, after_newline);
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_save_leftover(buffer);
	return (line);
}
