/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:37:04 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/27 14:39:48 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_point_len(unsigned long nbr)
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

void	ft_hex_to_str(unsigned long nbr)
{
	if (nbr >= 16)
	{
		ft_hex_to_str (nbr / 16);
		ft_hex_to_str (nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long ptr)
{
	unsigned int	len;

	len = 0;
	if (ptr == 0)
		len = ft_print_str("(nil)");
	else
	{
		len = ft_print_str("0x");
		ft_hex_to_str(ptr);
		len += ft_point_len(ptr);
	}
	return (len);
}
