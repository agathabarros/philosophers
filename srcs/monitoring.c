/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:32:35 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/26 19:20:04 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_meals(t_table *table)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i]->meals_done);
		if (table->philos[i]->counter >= table->num_ph_eat)
			count++;
		pthread_mutex_unlock(&table->philos[i]->meals_done);
		i++;
	}
	if (count == table->num_philos)
	{
		printf(CYAN "\n%d philosophers ate %d times\n",
			table->num_philos, table->num_ph_eat);
		pthread_mutex_lock(&table->finish_eating);
		table->dinner_done = 1;
		pthread_mutex_unlock(&table->finish_eating);
		return (1);
	}
	return (0);
}

int	if_dead(t_table *table)
{
	int	i;
	int	since_last_meal;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i]->last_meal);
		since_last_meal = get_time(table->start_time)
			- table->philos[i]->t_last_meal;
		pthread_mutex_unlock(&table->philos[i]->last_meal);
		if (since_last_meal >= table->time_to_die)
		{
			if (table->num_philos == 1)
				return (1);
			printf("%d %d died\n", (int)get_time(
					table->start_time), table->philos[i]->id + 1);
			pthread_mutex_lock(&table->finish_eating);
			table->dinner_done = 1;
			pthread_mutex_unlock(&table->finish_eating);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_table		*table;
	int			dead;

	table = (t_table *)arg;
	pthread_mutex_lock(&table->finish_eating);
	dead = table->dinner_done;
	pthread_mutex_unlock(&table->finish_eating);
	if (dead)
		return (NULL);
	while (dead == 0)
	{
		if (table->num_ph_eat != -1)
		{
			if (check_meals(table))
				return (NULL);
		}
		if (if_dead(table))
			return (NULL);
	}
	return (NULL);
}
