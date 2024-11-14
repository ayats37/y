/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 02:13:31 by taya              #+#    #+#             */
/*   Updated: 2024/10/03 15:50:59 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		i++;
	}
	ft_putstr_fd(str, 1);
	return (i);
}

/*int	main(void)
{
	printf("\n%d\n", ft_print_string((char *)NULL));
	printf("%s\n", (char *)NULL);
}*/
