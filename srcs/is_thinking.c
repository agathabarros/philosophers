/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:56:26 by agpereir          #+#    #+#             */
/*   Updated: 2024/03/27 14:09:38 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void is_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->msg);
	printf("%lld %d is thinking\n", 
				(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
}