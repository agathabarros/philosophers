/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:34:07 by agpereir          #+#    #+#             */
/*   Updated: 2024/03/26 11:40:51 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_empty(char **av)
{
	int i;
	i = 0;
	while(av[i])
	{
		if(av[i][0] == '\0')
		{
			printf("empty arg");
			return(0);
		}
		i++;
	}
	return(1);
}
int check_digit(char **av)
{
	int i;
	int j;
	i = 1;
	j = 0;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if(!ft_isdigit(av[i][j]) && av[i][j] > 32)
			{
				printf("error: arg inv");
				return(0);
			}
			j++;
		}
		i++;
	}
	return(1);
}
int	parse_args(t_table *table, char **av)
{
	if(!check_empty(av))
		return(0);
	table->num_philos = ft_atoi(av[1]);
	if(table->num_philos == 0)
		return(0);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->num_ph_eat = 0;
	if (av[5])
	{
		table->num_ph_eat = ft_atoi(av[5]);
		printf("%d", table->num_ph_eat);
		if(table->num_ph_eat == 0)
			return(0);
	}
	if(table->num_philos < 0 || table->time_to_sleep < 0
			|| table->time_to_eat < 0 || table->time_to_sleep < 0
			|| table->num_ph_eat < 0)
	{
		printf("error: arg invalide!");
		return(0);
	}
	return (1);
}
