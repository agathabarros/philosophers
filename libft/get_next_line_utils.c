/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:44:57 by agpereir          #+#    #+#             */
/*   Updated: 2023/12/06 15:28:57 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_gnl(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	int		i;
	int		a;
	char	*str;

	i = ft_strlen(str1);
	a = ft_strlen(str2);
	str = malloc(sizeof(char) * ((i + a) + 1));
	if (!str)
		return (0);
	i = 0;
	a = 0;
	while (str1[i])
		str[a++] = str1[i++];
	i = 0;
	while (str2[i])
		str[a++] = str2[i++];
	str[a] = '\0';
	free(str1);
	return (str);
}

