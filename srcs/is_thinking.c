/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:56:26 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/26 14:36:19 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	thinking(t_philo *philo)
{
	int	finish;

	pthread_mutex_lock(&philo->table->finish_eating);
	finish = philo->table->dinner_done;
	pthread_mutex_unlock(&philo->table->finish_eating);
	pthread_mutex_lock(&philo->table->msg);
	if (finish == 0)
		printf(YELLOW "%d %d is thinking\n" RESET,
			(int)get_time((__uint64_t)philo->table->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->table->msg);
}
