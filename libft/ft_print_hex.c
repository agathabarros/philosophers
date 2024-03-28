/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:10:51 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/27 14:56:40 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_len(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

void	ft_hex_str(unsigned int nbr, const char u)
{
	if (nbr >= 16)
	{
		ft_hex_str(nbr / 16, u);
		ft_hex_str(nbr % 16, u);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar((nbr + '0'));
		else
		{
			if (u == 'x')
				ft_putchar(nbr - 10 + 'a');
			else if (u == 'X')
				ft_putchar(nbr - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int n, const char form)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ft_hex_str(n, form);
	len += ft_hex_len(n);
	return (len);
}
