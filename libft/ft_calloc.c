/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:33:03 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:06:50 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates the requested memory and returns a 
pointer to it. Calloc, unlike Malloc, 
sets the allocated memory to zero.*/
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(nitems * size);
	if (memory == NULL)
		return (0);
	while (i < nitems * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
