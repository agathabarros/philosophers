/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:44:51 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/17 15:59:11 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	left(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	time_to_die(philo);
	printf("%ld %d has taken a fork\n",
		(get_time() - philo->time), philo->id);
}

void	right(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	time_to_die(philo);
	printf("%ld %d has taken a fork\n",
		(get_time() - philo->time), philo->id);
}

void	pick_up(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		left(philo);
		right(philo);
	}
	else
	{
		right(philo);
		left(philo);
	}
}
