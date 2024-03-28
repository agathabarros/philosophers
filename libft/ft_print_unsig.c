/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:37:11 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/27 13:59:37 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*function to count the nbr*/
int	ft_nbrlen(unsigned int nbr, unsigned int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		i = 1;
		return (i);
	}
	while (nbr)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

char	*ft_utoa(unsigned int nbr)
{
	char		*aux;
	int			i;
	long int	len;

	i = ft_nbrlen(nbr, 10);
	len = nbr;
	aux = (char *)malloc(sizeof(char) * i + 1);
	if (!aux)
		return (NULL);
	aux[i] = '\0';
	if (len == 0)
		aux[0] = '0';
	aux[i--] = '\0';
	while (len)
	{
		aux[i--] = (len % 10) + '0';
		len = len / 10;
	}
	return (aux);
}

int	ft_print_unsig(unsigned int nbr)
{
	int		i;
	char	*str;

	str = ft_utoa(nbr);
	i = ft_print_str(str);
	free(str);
	return (i);
}
