/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:05:53 by agpereir          #+#    #+#             */
/*   Updated: 2023/04/18 14:54:28 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks whether a character is an alphabet or not.
0 - if the parameter isn't an alphabet
1 - if the parameter is an alphabet*/
#include "libft.h"

int	ft_isalpha(int c)
{
	return (((c >= 'a' ) && (c <= 'z')) || ((c >= 'A' ) && (c <= 'Z')));
}
