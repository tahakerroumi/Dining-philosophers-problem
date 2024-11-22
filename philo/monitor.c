/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:26:56 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/22 03:22:57 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	died_checker(t_philo *philo, size_t timetodie)
{
	pthread_mutex_lock(philo->meal_lock);
	if (current_moment() - philo->last_meal > timetodie)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	died(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->philos_nbr)
	{
		if (died_checker(&philo[i], philo->data->die_time))
		{
			message_update("died", &philo[i]);
			pthread_mutex_lock(philo[i].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[i].dead_lock);
			return (1);
		}
	}
	return (0);
}

int	all_ate(t_philo *philo)
{
	int	i;
	int	finished;

	if (philo->data->meals_nbr == -1)
		return (0);
	i = -1;
	finished = 0;
	while (++i < philo[0].data->philos_nbr)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].times_eaten >= philo[i].data->meals_nbr)
			finished++;
		pthread_mutex_unlock(philo[i].meal_lock);
	}
	if (finished == philo[i - 1].data->philos_nbr)
	{
		pthread_mutex_lock(philo->dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	return (0);
}
