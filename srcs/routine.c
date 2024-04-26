/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:09:21 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/26 12:55:33 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		finish;

	philo = (t_philo *)arg;
	finish = time_to_die(philo);
	while (finish == 0)
	{
		if (philo->id % 2 != 0)
			usleep(100);
		pthread_mutex_lock(&philo->table->finish_eating);
		finish = philo->table->dinner_done;
		pthread_mutex_unlock(&philo->table->finish_eating);
		if (finish == 1)
			return (NULL);
		eating(philo);
		sleeping(philo);
		usleep(2000);
		thinking(philo);
	}
	return (0);
}
