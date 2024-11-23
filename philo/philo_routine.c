/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:47 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/23 02:49:24 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	onlyone(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork_id);
	message_update("has taken a fork", philo);
	pthread_mutex_unlock(philo->r_fork_id);
}

void	dining(t_philo *philo)
{
	if (!(philo->philo_id == philo->data->philos_nbr))
	{
		philo->first_fork = philo->r_fork_id;
		philo->second_fork = philo->l_fork_id;
	}
	else
	{
		philo->first_fork = philo->l_fork_id;
		philo->second_fork = philo->r_fork_id;
	}
	pthread_mutex_lock(philo->first_fork);
	message_update("has taken a fork", philo);
	pthread_mutex_lock(philo->second_fork);
	message_update("has taken a fork", philo);
	message_update("is eating", philo);
	pthread_mutex_lock(philo->times_eaten_lock);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->times_eaten_lock);
	pthread_mutex_lock(philo->last_meal_lock);
	philo->last_meal = current_moment();
	pthread_mutex_unlock(philo->last_meal_lock);
	ft_myusleep(philo->data->eat_time, philo);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

void	sleeping(t_philo *philo)
{
	message_update("is sleeping", philo);
	ft_myusleep(philo->data->sleep_time, philo);
}

void	thinking(t_philo *philo)
{
	message_update("is thinking", philo);
	ft_myusleep(1, philo);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (!philo->data->philos_nbr)
		return (NULL);
	if (philo->data->philos_nbr == 1)
		return (onlyone(philo), NULL);
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (existing(philo))
	{
		dining(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (data);
}
