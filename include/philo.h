/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:52:41 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/26 16:53:40 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# define RESET		"\033[0m"
# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"

typedef pthread_mutex_t	t_mutex;

typedef struct s_table
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_ph_eat;
	int				dinner_done;
	long int		start_time;
	struct s_philo	**philos;
	t_mutex			*forks;
	t_mutex			finish_eating;
	t_mutex			sleeping;
	t_mutex			msg;
	pthread_t		monitor;
}	t_table;
typedef struct s_philo
{
	int				id;
	int				fork_left;
	int				fork_right;
	long int		t_last_meal;
	t_table			*table;
	pthread_t		philo;
	t_mutex			last_meal;
	t_mutex			meals_done;
	int				counter;
	long			time;
}	t_philo;

int				left(t_philo *philo);
int				right(t_philo *philo);
void			init_mutex(t_table *philo);
t_philo			*init_table(int i, t_table *infos);
t_philo			**init_all(t_table *table);
void			init_forks(t_table *philo);
void			*routine(void *arg);
void			*monitoring(void *arg);
bool			start_dinner(t_table *table, int ac, char **av);
void			set_args(t_table *infos, int ac, char **av);
int				check_args(t_table *infos, int ac);
void			hungry_ph(t_philo *philo, int finish);
__uint64_t		get_time(__uint64_t start_time);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
int				time_to_die(t_philo *philo);
int				ft_atoi(char *str);
void			destroy_philos(t_table table, t_philo **philos, int i);

#endif