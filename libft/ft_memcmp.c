/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:49:43 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:12:08 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compares the first n bytes of memory s1 and memory s2. 
Return < 0, s1 is less. return > 0, s2 is less. Return = 0.*/
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}
