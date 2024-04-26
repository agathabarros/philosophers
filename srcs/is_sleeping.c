/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:56:24 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/26 13:06:28 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping(t_philo *philo)
{
	int	finish;

	pthread_mutex_lock(&philo->table->finish_eating);
	finish = philo->table->dinner_done;
	pthread_mutex_unlock(&philo->table->finish_eating);
	pthread_mutex_lock(&philo->table->msg);
	if (finish == 0)
		printf(MAGENTA "%d %d is sleeping\n" RESET, (int)get_time(philo->table->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->table->msg);
	usleep(philo->table->time_to_sleep * 1000);
}
