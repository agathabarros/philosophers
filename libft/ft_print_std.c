/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_std.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:37:09 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/27 14:21:25 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long int n)
{
	long int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*print_char is the same function of putchar*/
int	ft_print_chr(char c)
{
	write(1, &c, 1);
	return (1);
}

/*print_char is the same function of putstr*/
int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = ft_strlen_pf(str);
	write (1, str, i);
	return (i);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

/*print_nbr, the output is decimal number, 
we can make this fuction with itoa and strlen*/
int	ft_print_nbr(int nbr)
{
	ft_putnbr(nbr);
	return (count(nbr));
}
