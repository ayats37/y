/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:02:57 by taya              #+#    #+#             */
/*   Updated: 2024/11/11 17:21:46 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_fd_node	*find_or_create_node(t_fd_node **head, int fd)
{
	t_fd_node	*new_node;
	t_fd_node	*current;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new_node = malloc(sizeof(t_fd_node));
	if (!new_node)
		return (NULL);
	new_node->buffer = NULL;
		//aya dont forget that u use this to tell that no data has been read for this fd yet:)
	new_node->fd = fd;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

char	*ft_read(int fd, char *buffer, t_fd_node **head)
{
	ssize_t	bytes_read;
	char	*new_buffer;
	char	temp[BUFFER_SIZE + 1];

	if (!buffer)
		buffer = ft_strdup("");
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			//free(buffer);
			free_nodes_no_needed(head, fd);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		new_buffer = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = new_buffer;
		if (!buffer)
			return(NULL);
	}
	if (buffer[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
char	*ft_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strncpy(line, buffer, i);
	line[i] = '\0';
	return (line);
}

char	*ft_save_leftover(char *buffer)
{
	char	*after_newline;
	char	*leftover;

	after_newline = ft_strchr(buffer, '\n');
	if (!after_newline)
	{
		free(buffer);
		return (NULL);
	}
	after_newline++;
	leftover = ft_strdup(after_newline);
	free(buffer);
	return (leftover);
}
char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		len;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (*s1)
	{
		s3[i++] = *s1++;
	}
	while (*s2)
	{
		s3[i++] = *s2++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	int		len;
	int		i;

	len = ft_strlen(s);
	d = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!d)
		return (NULL);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void free_nodes_no_needed(t_fd_node **head, int fd)
{
	t_fd_node *current;
	t_fd_node *prev;
	
	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (current->buffer)
			{
				free(current->buffer);
				current->buffer = NULL;
			}
			if (prev)
				prev->next = current->next;
			else 
				*head = current->next;
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
}
