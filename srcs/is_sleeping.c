/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:56:24 by agpereir          #+#    #+#             */
/*   Updated: 2024/03/27 14:09:42 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->msg);
	printf("%ld %d is sleeping\n", 
				(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
	ft_usleep(philo->table.time_to_sleep, get_time(), NULL);
}