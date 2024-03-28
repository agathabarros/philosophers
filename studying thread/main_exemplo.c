/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:17:09 by agpereir          #+#    #+#             */
/*   Updated: 2024/03/09 18:53:46 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

pthread_mutex_t forks[5]; //mutex for each fork
pthread_t philos[5]; //threads for each philosopher

void *philo(void *arg)
{
	int id = *(int *)arg; //id of the philosopher
	int left_fork = id; //id of the left fork
	int right_fork = (id + 1) % 5; //id of the right fork

	while (1)
	{
		// think 
		printf("Philosopher %d is thinking\n", id);
		usleep(rand() % 1000);
		
		// get forks
		printf("Philosopher %d is hungry\n", id);
		pthread_mutex_lock(&forks[left_fork]); //lock left fork
		pthread_mutex_lock(&forks[right_fork]); //lock right fork
		printf("Philosopher %d picked up forks\n", id);

		// eat
		printf("Philosopher %d is eating\n", id);
		usleep(rand() % 1000);

		// put forks down
		pthread_mutex_unlock(&forks[left_fork]); //unlock left fork
		pthread_mutex_unlock(&forks[right_fork]); //unlock right fork
		printf("Philosopher %d put down forks\n", id);

		
		
	}
	
	
}

int main()
{
	int i = 0;
	int id[5];
	// creat mutex for each fork
	while(i < 5)
	{
		pthread_mutex_init(&forks[i], NULL); //initialize mutex for each fork
		i++;
	}
	// create threads for each philosopher
	i = 0;
	while(i < 5)
	{
		id[i] = i;
		pthread_create(&philos[i], NULL, philo, &id[i]); //create thread for each philosopher
		i++;
	}
	while (1)
	{
		sleep(1);
	}
	
	// join threads
	i = 0;
	while(i < 5)
	{
		pthread_join(philos[i], NULL); //join thread for each philosopher
		i++;
	}
	// destroy mutex for each fork
	i = 0;
	while(i < 5)
	{
		pthread_mutex_destroy(&forks[i]); //destroy mutex for each fork
		i++;
	}
	return 0;
}
