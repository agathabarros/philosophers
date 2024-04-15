/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:32:25 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/15 14:14:38 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_philo(t_philo *philo, t_table table)
{
	int i;

	i = 0;
	philo->ch_death = (int *)malloc(sizeof(int));
	philo->meals_eaten = (int *)malloc(sizeof(int));
	if (!philo->ch_death || !philo->meals_eaten)
	{
		printf("Error: malloc failed, init philo\n");
		return (1);
	}
	philo->ch_death[0] = 1;
	philo->meals_eaten[0] = 0;
	while (i < table.num_philos)
	{
		philo[i].id = i + 1;
		philo[i].table = table;
		philo[i].ch_death = philo[0].ch_death;
		philo[i].meals_eaten = philo[0].meals_eaten;
		i++;
	}
	if (init_mutex(philo) || init_forks(philo))
		return (1);
	return (0);
}
int		start(t_philo *philo)
{
	int i;

	i = 0;
	if(!one_philo(philo))
		return (0);
	while (i < philo->table.num_philos)
	{
		philo[i].time = get_time();
		philo[i].t_last_meal = philo[i].time ;

		if (pthread_create(&philo[i].philo, NULL, &routine, &philo[i]) != 0 || pthread_detach(philo[i].philo))
		{
			pthread_mutex_lock(philo->msg);
			printf("Error: pthread_create\n");
			pthread_mutex_unlock(philo->msg);
			return (1);

		}
		i++;
	}
	return (0);
}
int init_forks(t_philo *philo)
{
    int i;
    
    i = 0;
    while(i < philo->table.num_philos)
    {
        philo[i].left_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        if(!philo[i].left_fork)
        {
            printf("Error: malloc failed, init fork\n");
            return (1);
        }
        pthread_mutex_init(philo[i].left_fork, NULL);
        i++;
    }
    i = 0;
    while(i < philo->table.num_philos)
    {
        if (i == 0)
            philo[i].right_fork = philo[philo->table.num_philos - 1].left_fork;
        else
            philo[i].right_fork = philo[i - 1].left_fork;
        i++;
    }
    return (0);
}

int init_mutex(t_philo *philo)
{
	int i;

	i = 0;
	philo->msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo->death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo->meals_done = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo->msg || !philo->death || !philo->meals_done)
	{
		printf("Error: malloc failed, init mutex\n");
		return (1);
	}
	pthread_mutex_init(philo->msg, NULL);
	pthread_mutex_init(philo->death, NULL);
	pthread_mutex_init(philo->meals_done, NULL);
	while (i < philo->table.num_philos)
	{
		philo[i].msg = philo->msg;
		philo[i].death = philo->death;
		philo[i].meals_done = philo->meals_done;
		i++;
	}
	return (0);
}
int one_philo(t_philo *philo)
{
	pthread_t tr_id = 0;
	if(philo->table.num_philos == 1)
	{
		philo->time = get_time();
		if(pthread_create(&tr_id, NULL, &routine_one, philo) != 0)
		{
			pthread_mutex_lock(philo->msg);
			printf("Error: pthread_create\n");
			return (0);
		}
		pthread_join(tr_id, NULL);
		return (0);
	}
	return (1);
}