/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:52:52 by agpereir          #+#    #+#             */
/*   Updated: 2023/04/24 15:50:39 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks whether a character is an num or not.
0 - if the parameter isn't a num
1 - if the parameter is a num*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
