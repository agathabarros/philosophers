/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:22:42 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/17 15:58:01 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (printf("Error: Function 'gettimeofday failed.\n"));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
