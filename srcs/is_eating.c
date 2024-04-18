/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:50:21 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/18 18:36:48 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_eating(t_philo *philo)
{
	philo->t_last_meal = get_time();
	pthread_mutex_lock(philo->msg);
	printf("\033[1;34m%ld %d is eating\n\033[0m",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
	ft_usleep(philo->table.time_to_eat, get_time(), NULL);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->table.num_ph_eat != 0)
	{
		philo->table.num_ph_eat--;
		if (philo->table.num_ph_eat == 0)
			return (0);
	}
	return (1);
}
