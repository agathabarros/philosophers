/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:04:35 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:07:05 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*takes a single argument in the 
form of an integer and returns the value of type 
0 - if the parameter isn't a numeric character.
1 - if the parameter is is a numeric character.*/
#include "libft.h"

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}
