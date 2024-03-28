/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:26:31 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:07:48 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates memory and returns a string representing 
the integer received as an argument. 
Negative numbers must be handled.*/
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

static char	function_aux(char *aux, long int len, int n, int i)
{
	aux[len] = '\0';
	while (i + 1 < len)
	{
		aux[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (*aux);
}

char	*ft_itoa(int n)
{
	char			*aux;
	int				i;
	long int		len;

	i = -1;
	len = count(n);
	aux = malloc(sizeof(char) * len + 1);
	if (!(aux))
		return (NULL);
	if (n == -2147483648)
	{
		aux[0] = '-';
		aux[1] = '2';
		n = 147483648;
		i = 1;
	}
	else if (n < 0)
	{
		aux[0] = '-';
		n *= -1;
		i = 0;
	}
	function_aux(aux, len, n, i);
	return (aux);
}
/*int main()
{
	
    printf("%s", ft_itoa(345));
	
}*/
