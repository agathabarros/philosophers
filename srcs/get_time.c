/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:22:42 by agpereir          #+#    #+#             */
/*   Updated: 2024/03/27 14:33:31 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


long	get_time(void)
{
	struct timeval	time;

	if(gettimeofday(&time, NULL))
		return (printf("Error: Function 'gettimeofday failed.\n"));
	return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
}