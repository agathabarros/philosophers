/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:26:47 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:07:03 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks whether a character is an ASCII character or not.
0 - if the parameter isn't an ASCII
1 - if the parameter is an ASCII*/
#include "libft.h"

int	ft_isascii(int c)
{
	return ((c >= 0) && (c <= 127));
}
