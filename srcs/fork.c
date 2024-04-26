/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:44:51 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/26 12:54:03 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	left(t_philo *philo)
{
	int	death;

	death = 0;
	pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
	pthread_mutex_lock(&philo->table->finish_eating);
	death = philo->table->dinner_done;
	pthread_mutex_unlock(&philo->table->finish_eating);
	pthread_mutex_unlock(&philo->table->msg);
	if (death == 0)
		printf("%d %d has taken a fork\n",
			(int)get_time((__uint64_t)philo->table->start_time), philo->id + 1);
	return (death);
}

int	right(t_philo *philo)
{
	int	death;

	death = 0;
	pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
	pthread_mutex_lock(&philo->table->finish_eating);
	death = philo->table->dinner_done;
	pthread_mutex_unlock(&philo->table->finish_eating);
	pthread_mutex_unlock(&philo->table->msg);
	if (death == 0)
		printf("%d %d has taken a fork\n",(int)get_time((__uint64_t)philo->table->start_time), philo->id + 1);
	return (death);
}