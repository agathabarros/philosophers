/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:47 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:16:04 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This returns a pointer to the first occurrence of 
the character c in the string str, or NULL 
if the character is not found. 
Searches for the last occurrence 
of the character c in the string pointed to by s.*/
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	aux;
	int		i;

	i = 0;
	aux = (char)c;
	while (str[i] != '\0' && str[i] != aux)
		i++;
	if (str[i] == aux)
		return (& ((char *)str)[i]);
	return (NULL);
}
