/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:24:29 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:19:34 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates memory and returns a new string, 
which is the result of concatenating 's1' and 's2'.*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (aux == NULL )
		return (0);
	while (s1[i] != '\0')
	{
		aux[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		aux[i] = s2[j];
		i++;
		j++;
	}
	aux[i] = '\0';
	return (aux);
}
