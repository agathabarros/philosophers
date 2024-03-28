/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:54 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:20:15 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function copies up to size - 1 
characters from the NUL-terminated string src to dst,
NUL-terminating the result. 
Copy string from src to dest up to size.*/
#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;

	x = ft_strlen(src);
	y = 0;
	if (size != 0)
	{
		while (src[y] != '\0' && y < size -1)
		{
			dest[y] = src[y];
			y++;
		}
		dest[y] = '\0';
	}
	return (x);
}
