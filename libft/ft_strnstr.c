/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:36:03 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:21:10 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Finds the first substring(little) 
in a string(big) with limited length(len).*/
#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	l = 0;
	if (little[l] == 0)
		return ((char *)big);
	while (big[b])
	{
		while (big[b + l] && big[b + l] == little[l] && len > (l + b))
			l++;
		if (!(little[l]))
			return ((char *)big + b);
		l = 0;
		b++;
	}
	return (0);
}
/*int main()
{
    char *a = "lorem ipsum dolor sit amet";
    char *b = "ipsumm";
    printf("%s\n", ft_strnstr(a,b, 30));
}*/
