/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:36:34 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/29 14:08:19 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_philos(t_table table, t_philo **philos, int i)
{
	while (i < table.num_philos)
	{
		pthread_mutex_destroy(&table.forks[i]);
		free(philos[i]);
		i++;
	}
}

void	set_args(t_table *infos, int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		infos->start_time = get_time(0);
		infos->num_philos = ft_atoi(av[1]);
		infos->time_to_die = ft_atoi(av[2]);
		infos->time_to_eat = ft_atoi(av[3]);
		infos->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			infos->num_ph_eat = ft_atoi(av[5]);
		else
			infos->num_ph_eat = -1;
	}
}

int	check_args(t_table *infos, int ac)
{
	if (ac < 5 || ac > 6)
		return (printf("Try: ./philo <number_of_philos>"\
			" <time_to_die> <time_to_eat> <time_to_sleep> "\
			"\n[number_of_times_each_philosopher_must_eat] (optional)\n"));
	if (infos->num_philos < 1)
		return (printf("Erro: missing philos\n"));
	if (infos->time_to_die < 1)
		return (printf("Erro: time to die\n"));
	if (infos->time_to_eat < 1)
		return (printf("Erro: time to eat\n"));
	if (infos->time_to_sleep < 1)
		return (printf("Erro: time to sleep\n"));
	if (ac == 6 && (infos->num_ph_eat < 1))
		return (printf("Erro: meals to eat\n"));
	return (0);
}

int	time_to_die(t_philo *philo)
{
	int	finish;

	finish = 0;
	if (philo->table->num_philos == 1)
	{
		pthread_mutex_lock(&philo->table->msg);
		printf("%ld %d has taken a fork\n", philo->t_last_meal, philo->id + 1);
		pthread_mutex_unlock(&philo->table->msg);
		printf("%d %d died\n", (int)get_time((__uint64_t)
				philo->table->start_time), philo->id + 1);
		pthread_mutex_lock(&philo->table->finish_eating);
		philo->table->dinner_done = 1;
		pthread_mutex_unlock(&philo->table->finish_eating);
	}
	return (finish);
}

void	hungry_ph(t_philo *philo, int finish)
{
	pthread_mutex_lock(&philo->table->msg);
	if (finish == 0)
		printf(BLUE "%d %d is eating\n" RESET, (int)get_time((__uint64_t)
				philo->table->start_time), philo->id + 1);
	if (philo->table->num_ph_eat != -1)
	{
		pthread_mutex_lock(&philo->meals_done);
		philo->counter++;
		pthread_mutex_unlock(&philo->meals_done);
	}
	pthread_mutex_unlock(&philo->table->msg);
	pthread_mutex_lock(&philo->last_meal);
	philo->t_last_meal = get_time(philo->table->start_time);
	pthread_mutex_unlock(&philo->last_meal);
	usleep(philo->table->time_to_eat * 1000);
}
