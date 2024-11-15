/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:47 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/15 12:42:07 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    pick_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork_id);
    message_update("has taken a fork", philo);
    pthread_mutex_lock(philo->l_fork_id);
    message_update("has taken a fork", philo);
}

void    dining(t_philo *philo)
{
    pthread_mutex_lock(philo->meal_lock);
    philo->data->current_time = current_moment();
    ft_myusleep(philo->data->eat_time);
    message_update("is eating", philo);
    philo->times_eaten++;
}

void    sleeping(t_philo *philo)
{
    message_update("is sleeping", philo);
    ft_myusleep(philo->data->sleep_time);
    message_update("is thinking", philo);
}

// void    priority_waiting(t_philo *philo)
// {
//     if (philo->philo_id % 2 == 0 || philo->philo_id != (philo->data->philos_nbr - 1))
//         ft_myusleep(77777);
//     else
//         return ;
// }

void    *philo_routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    philo->data->current_time = current_moment();
    // priority_waiting(philo);
    while (1)
    {
        pick_fork(philo);
        dining(philo);
        sleeping(philo);
    }
    return (NULL);
}
