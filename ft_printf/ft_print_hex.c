/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:49:18 by taya              #+#    #+#             */
/*   Updated: 2024/10/03 15:06:19 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (str[i])
	{
		i++;
	}
	i--;
	while (j < i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j++;
		i--;
	}
}

char	ft_check_upper_or_lower(unsigned int r, int upper_or_lower)
{
	if (upper_or_lower == 1)
		return (r + 'A' - 10);
	else
		return (r + 'a' - 10);
}

char	*ft_cnv_dth(unsigned int n, int upper_or_lower)
{
	char			*str;
	unsigned int	i;
	unsigned int	r;

	i = 0;
	str = malloc(9 * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		r = n % 16;
		if (r < 10)
			str[i++] = r + '0';
		else
			str[i++] = ft_check_upper_or_lower(r, upper_or_lower);
		n = n / 16;
	}
	ft_strrev(str);
	str[i] = '\0';
	return (str);
}

int	ft_print_hex(int n, int upper_or_lower)
{
	char	*hex_str;
	int		i;

	i = 0;
	hex_str = ft_cnv_dth(n, upper_or_lower);
	while (hex_str[i])
	{
		write(1, &hex_str[i], 1);
		i++;
	}
	free(hex_str);
	return (i);
}

/*int	main(void)
{
	printf("\n%d\n", ft_print_hex(2147483647, 0));
}*/
