/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:03:07 by taya              #+#    #+#             */
/*   Updated: 2024/11/11 03:12:32 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_BONUS
# define GET_NEXT_LINE_H_BONUS

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct s_fd_node
{
	int					fd;
	char				*buffer;
	struct s_fd_node	*next;
}						t_fd_node;

size_t					ft_strlen(const char *str);
char	*ft_line(char *buffer);
char	*ft_save_leftover(char *buffer);
char					*ft_strchr(const char *str, int c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strdup(const char *s);
char					*ft_strncpy(char *dest, const char *src, int len);
char	*ft_read(int fd, char *buffer, t_fd_node **head);
char					*ft_save_leftover(char *buffer);
char	*get_next_line(int fd);
void free_nodes_no_needed(t_fd_node **head, int fd);
t_fd_node	*find_or_create_node(t_fd_node **head, int fd);
#endif