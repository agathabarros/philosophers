/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:51:31 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:04:26 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function returns the converted integral number as an int value. 
If no valid conversion could be performed, it returns zero. 
Converts String to integers.*/
#include "libft.h"

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	int			result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}
/*int main(void)
{
		 printf("%s", "ft_atoi");
    printf("%s", "\n");
    printf("%d",ft_atoi("\010 9"));
   
    printf("%s", "\n");
     printf("%s\n", "----------------");

}*/
