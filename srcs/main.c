#include "../include/philo.h"

void free_all(t_philo *table)
{
	int i;

	i=0;

	pthread_mutex_destroy(table[i].meals_done);
	pthread_mutex_destroy(table[i].death);
	pthread_mutex_destroy(table[i].msg);
	while(i < table->table.num_philos)
	{
		pthread_mutex_destroy(table[i].left_fork);
		free(table[i].left_fork);
		i++;
	}
	free(table->meals_done);
	free(table->death);
	free(table->msg);
	free(table->ch_death);
	free(table->meals_eaten);
	free(table);
	
}
void wait_ph(t_philo *philo, int num_meals)
{
	while(1)
	{
		pthread_mutex_lock(philo->death);
		if(*(philo->ch_death) == 0)
			break;
		pthread_mutex_unlock(philo->death);	
			
		pthread_mutex_lock(philo->meals_done);
		if(*(philo->meals_eaten) == num_meals)
			break;		
		pthread_mutex_unlock(philo->meals_done);		
		usleep(50);
	}
}
int	main(int ac, char **av)
{
	t_table		table;
	t_philo		*philo;

	if (ac == 5 || ac == 6)
	{
		if (!(parse_args(&table, av)) || !check_digit(av))
			return (0);
		philo = (t_philo *)malloc(sizeof(t_philo) * table.num_philos);
		if (philo == NULL)
			return (printf("Error: malloc failed, memory was not allocated :/\n"));
		
		if (init_philo(philo, table) || start(philo))
			return (0);
		wait_ph(philo, table.num_philos);
		free_all(philo);
	}
	else
	{
		return (printf("Error: wrong number of arguments\n"));
	}
}