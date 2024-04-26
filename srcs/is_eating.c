/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:50:21 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/24 21:02:56 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating(t_philo *philo)
{
	int	finish;

	pthread_mutex_lock(&philo->table->finish_eating);
	finish = philo->table->dinner_done;
	pthread_mutex_unlock(&philo->table->finish_eating);
	if (philo->id % 2 != 0)
	{
		finish = right(philo);
		finish = left(philo);
		hungry_ph(philo, finish);
		pthread_mutex_unlock(&philo->table->forks[philo->fork_left]);
		pthread_mutex_unlock(&philo->table->forks[philo->fork_right]);
	}
	else
	{
		finish = left(philo);
		finish = right(philo);
		hungry_ph(philo, finish);
		pthread_mutex_unlock(&philo->table->forks[philo->fork_right]);
		pthread_mutex_unlock(&philo->table->forks[philo->fork_left]);
	}
}
