/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 03:32:52 by taya              #+#    #+#             */
/*   Updated: 2024/10/03 15:22:33 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_unsigned(unsigned int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	if (n == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	nbr = n;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	return (i);
}

/*int	main(void)
{
	printf("\n%d\n", ft_print_unsigned(7));
}*/
