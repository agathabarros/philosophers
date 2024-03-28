/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:36:06 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:22:06 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Converts uppercase letters to lowercase.*/
#include "libft.h"

int	ft_tolower(int arg)
{
	if ((arg >= 'A' ) && (arg <= 'Z'))
		return (arg += 32);
	else
		return (arg);
}
