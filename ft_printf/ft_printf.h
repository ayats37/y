/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:19:54 by taya              #+#    #+#             */
/*   Updated: 2024/10/03 15:36:34 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_percent(void);
int		ft_print_int(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(int n, int upper_or_lower);
int		ft_print_pointer(void *pointer);
int		ft_printf(const char *str_input, ...);

#endif
