/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:19 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:05:26 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Erases the data in the first n bytes of memory 
from the location pointed to by s 
and writes zeros in their place.*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*new;
	size_t			i;

	i = 0;
	new = (unsigned char *)s;
	while (i < n)
	{
		new[i] = 0;
		i++;
	}
}
