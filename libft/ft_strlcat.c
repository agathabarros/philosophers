/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:07:51 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:19:57 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Appends the src string to the end of the dst string.*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	n;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	n = dst_len;
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && size > n + 1)
	{
		dst[n] = src[i];
		n++;
		i++;
	}
	dst[n] = '\0';
	return (dst_len + src_len);
}
