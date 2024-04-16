/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:44:51 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/16 14:33:19 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	left(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	time_to_die(philo);
	pthread_mutex_lock(philo->msg);
	printf("%ld %d has taken a fork\n", 
				(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);

}
void right(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	time_to_die(philo);
	pthread_mutex_lock(philo->msg);
	printf("%ld %d has taken a fork\n", 
				(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
}
