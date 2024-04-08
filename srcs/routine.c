/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:09:21 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/01 12:22:36 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void time_to_die(t_philo *philo)
{
	if((get_time()- philo->t_last_meal) >= philo->table.time_to_die)
	{
		pthread_mutex_lock(philo->msg);
		pthread_mutex_lock(philo->death);
		*(philo->ch_death) = 0;
		printf("All philos are full\n");
		pthread_mutex_unlock(philo->death);
		
	}
}
void ft_usleep(int time_sleep, long long exec_time, t_philo *philo)
{
	while(1)
	{
		usleep(50);
		if(philo)
			time_to_die(philo);
		if(((get_time() - exec_time)) >= time_sleep)
			break;
	}
}
/*
** Routine for the philo to take the left fork
** and print the message
** 
*/
void* routine_one(void* args)
{
	t_philo *philo;
	
	philo = (t_philo *)args;
	pthread_mutex_lock(philo->msg);
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork\n", 
				(get_time() - philo->time), philo->id);
	ft_usleep(philo->table.time_to_die, get_time(), NULL);
	pthread_mutex_lock(philo->death);
	*(philo->ch_death) = 0;
	printf("All philos are full\n");
	pthread_mutex_unlock(philo->death);
	return (NULL);
}
void* routine(void* args)
{
	t_philo *philo;
	
	philo = (t_philo *)args;
	if(philo->id % 2 == 0)
		ft_usleep(30, get_time(), NULL);
	while (1)
	{
		time_to_die(philo);
		left(philo);
		right(philo);
		if(!is_eating(philo))
			break;
		is_sleeping(philo);
		is_thinking(philo);
	}
	pthread_mutex_lock(philo->meals_done);
	*(philo->meals_eaten) += 1;
	pthread_mutex_unlock(philo->meals_done);
	return (NULL);
}