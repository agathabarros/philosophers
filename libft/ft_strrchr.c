/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:53:13 by agpereir          #+#    #+#             */
/*   Updated: 2023/04/26 12:27:32 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*searches for the last occurrence of the character c 
(an unsigned char) in the string pointed to, 
by the argument str.
This function returns a pointer to the last 
occurrence of character in str. If the value is not found, 
the function returns a null pointer.*/
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
