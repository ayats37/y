/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:20:08 by taya              #+#    #+#             */
/*   Updated: 2024/11/11 21:26:08 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_int(int n)
{
	unsigned int	nb;
	int				i;

	i = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		nb = (unsigned int)-n;
		i++;
	}
	else
		nb = (unsigned int)n;
	if (nb <= 9)
		i++;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	return (i);
}

