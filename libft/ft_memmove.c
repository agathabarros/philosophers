/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:35 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:13:30 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Copies n characters from src to dest, but for 
overlapping memory blocks, memmove() is a safer approach than memcpy().*/
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (((unsigned char *)dest) == ((unsigned char *)src))
		return (dest);
	if (dest > src)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
/*int main()
{
    printf("%s\n", "ft_memmove");
	printf("%p\n", ft_memmove("barros", "agatha", 50));
    printf("%s\n", "----------------");
}*/
