/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:47 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/22 03:38:10 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	onlyone(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork_id);
	message_update("has taken a fork", philo);
	pthread_mutex_unlock(philo->r_fork_id);
}

int	existing(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (1);
}

void	dining(t_philo *philo)
{
	if (philo->l_fork_id > philo->r_fork_id)
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
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = current_moment();
	pthread_mutex_unlock(philo->meal_lock);
	ft_myusleep(philo->data->eat_time, philo);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	pthread_mutex_lock(philo->eat_m_nbr);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->eat_m_nbr);
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
