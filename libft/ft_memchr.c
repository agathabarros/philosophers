/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:28 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:11:30 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Searches for the first occurrence of the character c 
in the first n bytes of the string pointed to by s. 
Returns a pointer to the corresponding byte.*/
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*aux;
	size_t	i;

	i = 0;
	aux = (char *)str;
	while (i < n)
	{
		if (aux[i] == (char)c)
			return (&aux[i]);
		i++;
	}
	return (NULL);
}
