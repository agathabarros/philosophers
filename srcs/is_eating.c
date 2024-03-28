/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:50:21 by agpereir          #+#    #+#             */
/*   Updated: 2024/03/27 14:09:47 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int is_eating(t_philo *philo)
{
	philo->t_last_meal = get_time();
	pthread_mutex_lock(philo->msg);
	printf("%lld %d is eating\n", 
				(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
	usleep(philo->table.time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}