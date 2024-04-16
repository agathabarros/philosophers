/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:50:21 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/16 14:41:57 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int is_eating(t_philo *philo)
{
	philo->t_last_meal = get_time();
	pthread_mutex_lock(philo->msg);
	printf("%ld %d is eating\n", 
				(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
	ft_usleep(philo->table.time_to_eat, get_time(), NULL);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if(philo->table.num_ph_eat != 0)
	{
		philo->table.num_ph_eat--;
		if(philo->table.num_ph_eat == 0)
			return(0);
	}
	return (1);
}