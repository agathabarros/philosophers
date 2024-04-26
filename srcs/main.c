/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:56:19 by agpereir          #+#    #+#             */
/*   Updated: 2024/04/26 19:01:28 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	start_dinner(t_table *table, int ac, char **av)
{
	set_args(table, ac, av);
	if (!check_args(table, ac))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_table		table;
	t_philo		**philos;
	int			i;

	i = 0;
	table = (t_table){0};
	init_mutex(&table);
	if (start_dinner(&table, ac, av))
		return (1);
	philos = init_all(&table);
	destroy_philos(table, philos, i);
	free(table.forks);
	free(philos);
	return (0);
}
