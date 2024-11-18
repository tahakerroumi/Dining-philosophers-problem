/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:26:56 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/18 11:06:06 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	died_checker(t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->meal_lock);
	time = current_moment() - philo->last_meal;
	if ((time >= philo->data->die_time) && (philo->eating == 0))
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
		if (died_checker(&philo[i]))
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
void	*monitor_work(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		if (died(philo) == 1 || all_ate(philo) == 1)
			break ;
	}
	return (data);
}
