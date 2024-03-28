/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:36:10 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:22:45 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Convert lowercase letters to uppercase.*/
#include "libft.h"

int	ft_toupper(int arg)
{
	if ((arg >= 'a' ) && (arg <= 'z'))
		return (arg -= 32);
	else
		return (arg);
}
