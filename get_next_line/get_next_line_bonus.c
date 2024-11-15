/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:33:19 by taya              #+#    #+#             */
/*   Updated: 2024/11/15 19:04:51 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fd_node	*head;
	t_fd_node			*node;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = find_or_create_node(&head, fd);
	if (!node) 
		return (NULL);
	node->buffer = ft_read(fd, (node->buffer));
	if (!node->buffer)
	{
		free_nodes_no_needed(&head, fd); 
		return (NULL);
	}
	line = ft_line(node->buffer);
	if (!line) 
	{
		free_nodes_no_needed(&head, fd);
		return (NULL);
	}
	node->buffer = ft_save_leftover(node->buffer);
	if (!node->buffer)
		free_nodes_no_needed(&head, fd);
	return (line);
}