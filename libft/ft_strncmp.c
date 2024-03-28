/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:59 by agpereir          #+#    #+#             */
/*   Updated: 2024/02/24 16:52:02 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*compares at most the first n bytes of str1 and str2.*/
#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	x;

	x = 0;
	while (x < n)
	{
		if (s1[x] != s2[x] || s1[x] == '\0')
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		else
			x++;
	}
	if (n == 0)
		return (0);
	return (0);
}
/*int main()
{
	printf("%d", ft_strncmp("test\200", "test\0", 6));

}*/
