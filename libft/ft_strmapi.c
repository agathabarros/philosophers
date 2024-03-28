/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:26:56 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:20:26 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applies the function ’f’ to each character of the string ’s’* 
to create a new string (with malloc(3)) 
resulting from successive* applications of ’f’.**/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*aux;
	unsigned int	i;

	i = 0;
	aux = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!aux)
		return (NULL);
	if (!s || !f)
		return (NULL);
	while (s[i])
	{
		aux[i] = (*f)(i, s[i]);
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
