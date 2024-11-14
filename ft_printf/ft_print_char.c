/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:16:36 by taya              #+#    #+#             */
/*   Updated: 2024/10/03 15:22:15 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

/*int	main(void)
{
	printf("\n%d\n", ft_print_char('c'));
}*/
