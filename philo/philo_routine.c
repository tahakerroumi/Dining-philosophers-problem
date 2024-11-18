/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:47 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/18 04:55:19 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    pick_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork_id);
    message_update("has taken a fork", philo);
    if (philo->data->philos_nbr == 1)
    {
        ft_myusleep(philo->data->die_time);
        pthread_mutex_unlock(philo->r_fork_id);
        return ;
    }
    pthread_mutex_lock(philo->l_fork_id);
    message_update("has taken a fork", philo);
}

void    dining(t_philo *philo)
{
    philo->eating = 1;
    message_update("is eating", philo);
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = current_moment();
    philo->times_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
    ft_myusleep(philo->data->eat_time);
    philo->eating = 0;
    pthread_mutex_unlock(philo->r_fork_id);
    pthread_mutex_unlock(philo->l_fork_id);
}

void    sleeping(t_philo *philo)
{
    message_update("is sleeping", philo);
    ft_myusleep(philo->data->sleep_time);
    message_update("is thinking", philo);
}

int existing(t_philo *philo)
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

void    *philo_routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    if (philo->philo_id & 1 == 1)
        ft_myusleep(1);
    while (existing(philo) != 0)
    {
        pick_fork(philo);
        dining(philo);
        sleeping(philo);
    }
    return (data);
}
