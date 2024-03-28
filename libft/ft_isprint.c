/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:27:09 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:07:08 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks whether a character is a printable character or not. 
1 - if the parameter isn't a printable character.
0 - if the parameter is a printable character*/
#include "libft.h"

int	ft_isprint(int c)
{
	return ((c >= 32) && (c <= 126));
}
