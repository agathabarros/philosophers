/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:32:25 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/29 14:09:24 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_mutex(t_table *philo)
{
	pthread_mutex_init(&philo->finish_eating, NULL);
	pthread_mutex_init(&philo->sleeping, NULL);
	pthread_mutex_init(&philo->msg, NULL);
}

t_philo	*init_table(int i, t_table *infos)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->table = infos;
	philo->id = i;
	philo->fork_right = i;
	philo->t_last_meal = (int)get_time(infos->start_time);
	philo->counter = 0;
	pthread_mutex_init(&philo->meals_done, NULL);
	pthread_mutex_init(&philo->last_meal, NULL);
	if (i > 0)
		philo->fork_left = i - 1;
	else
		philo->fork_left = infos->num_philos - 1;
	if (pthread_create(&philo->philo, NULL, &routine, philo) != 0)
	{
		printf("error creating thread\n");
		return (NULL);
	}
	return (philo);
}

void	init_forks(t_table *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philos);
	if (!info->forks)
		return ;
	while (i < info->num_philos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
		{
			printf("erro mutex\n");
			return ;
		}
		i++;
	}
}

t_philo	**init_all(t_table *table)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo *) * table->num_philos);
	i = -1;
	if (!philos)
		return (NULL);
	init_forks(table);
	while (++i < table->num_philos)
		philos[i] = init_table(i, table);
	i = -1;
	table->philos = philos;
	if (pthread_create(&table->monitor, NULL,
			&monitoring, table) != 0)
		return (NULL);
	while (++i < table->num_philos)
		pthread_join(philos[i]->philo, NULL);
	pthread_join(table->monitor, NULL);
	pthread_mutex_destroy(&table->finish_eating);
	pthread_mutex_destroy(&table->sleeping);
	pthread_mutex_destroy(&table->msg);
	return (table->philos);
}
