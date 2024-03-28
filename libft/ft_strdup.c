/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:24:22 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:16:56 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function returns a pointer to a 
new string which is a 
duplicate of the string s.
Returns a pointer to a string 
(created with malloc), which is a duplicate 
of the string pointed to by s.*/
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*str;
	int			size;
	int			i;

	size = 0;
	while (s[size])
		size++;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
