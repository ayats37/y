/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 02:59:43 by taya              #+#    #+#             */
/*   Updated: 2024/10/02 01:00:26 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_strrev(char *str)
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

char	*ft_cnv_dth_ptr(unsigned long long n)
{
	char				*str;
	unsigned int		i;
	unsigned long long	r;

	i = 0;
	str = malloc(17 * sizeof(char));
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
			str[i++] = r + 'a' - 10;
		n = n / 16;
	}
	ft_strrev(str);
	str[i] = '\0';
	return (str);
}

int	ft_print_hex_ptr(unsigned long long n)
{
	char	*hex_str;
	int		i;

	i = 0;
	hex_str = ft_cnv_dth_ptr(n);
	while (hex_str[i])
	{
		write(1, &hex_str[i], 1);
		i++;
	}
	free(hex_str);
	return (i);
}

int	ft_print_pointer(void *pointer)
{
	int	print_chars;

	print_chars = 0;
	if (pointer == NULL)
	{
		print_chars += write(1, "0x0", 3);
		return (print_chars);
	}
	print_chars += write(1, "0x", 2);
	print_chars += ft_print_hex_ptr((unsigned long long)pointer);
	return (print_chars);
}

/*int	main(void)
{
	printf("\n%d\n", ft_print_pointer("helloaya"));
}*/
