/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:23:14 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:21:41 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*function returns the substring
of a given string between two given indices.*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	size_t				j;
	char				*str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = start;
	j = 0;
	str = malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*int main()
{
    char src[] = "substrr function Implementation";
 
    int m = 0;
    int n = 5;
 
    char* dest = ft_substr(src, m, n);
 	
    printf("%s\n", dest);

	
    return 0;
}*/
