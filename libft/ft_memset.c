/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:44 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:14:17 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  memset() function fills the first n bytes 
of the memory area pointed to by
s with the constant byte c.
We use this function before a operation, 
is like a memory "reset"
Copies the character c to the first n characters 
of the string pointed to by s.*/
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux;

	i = 0;
	aux = (unsigned char *)str;
	while (i < n)
		aux[i++] = (unsigned char)c;
	return (str);
}
