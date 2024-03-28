/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:52:41 by agpereir          #+#    #+#             */
/*   Updated: 2024/03/27 14:33:03 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "../libft/libft.h"

// Color codes
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

typedef pthread_mutex_t	t_mutex;

typedef struct s_table
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_ph_eat;
}	t_table;
typedef struct s_philo
{
	int				id;
	long int		t_last_meal;
	t_table			table;
	pthread_t		philo;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	t_mutex			*msg;
	t_mutex			*death;
	t_mutex			*meals_done;
	int				*ch_death;
	int 			*meals_eaten;
	long			time;
}	t_philo;

int 	init_philo(t_philo *philo, t_table table);
int		start(t_philo *philo);
int 	init_forks(t_philo *philo);
int check_digit(char **av);
int 	init_mutex(t_philo *philo);
void* 	routine(void* args);
int	parse_args(t_table *table, char **av);
void	left(t_philo *philo);
void	right(t_philo *philo);
void is_sleeping(t_philo *philo);
void is_thinking(t_philo *philo);
int is_eating(t_philo *philo);
long	get_time(void);
void time_to_die(t_philo *philo);
void* routine_one(void* args);
int one_philo(t_philo *philo);
#endif