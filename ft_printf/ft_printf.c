/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:19:52 by taya              #+#    #+#             */
/*   Updated: 2024/11/11 21:29:21 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_input(const char input, va_list *args)
{
	int	i;

	i = 0;
	if (input == 'c')
		i += ft_print_char(va_arg(*args, int));
	else if (input == 'd' || input == 'i')
		i += ft_print_int(va_arg(*args, int));
	else if (input == 'u')
		i += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (input == 's')
		i += ft_print_string(va_arg(*args, char *));
	else if (input == 'p')
		i += ft_print_pointer(va_arg(*args, void *));
	else if (input == 'x')
		i += ft_print_hex(va_arg(*args, unsigned int), 0);
	else if (input == 'X')
		i += ft_print_hex(va_arg(*args, unsigned int), 1);
	else if (input == '%')
		i += ft_print_percent();
	return (i);
}

int	ft_printf(const char *str_input, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	va_start(args, str_input);
	while (str_input[i])
	{
		if (str_input[i] == '%')
		{
			if (str_input[i + 1])
			{
				j += ft_check_input(str_input[i + 1], &args);
				i++;
			}
		}
		else
		{
			j += ft_print_char(str_input[i]);
		}
		i++;
	}
	va_end(args);
	return (j);
}
