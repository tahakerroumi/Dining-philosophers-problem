/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:47 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/15 21:15:03 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int existing(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->dead = 1)
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
    philo->data->start_time = current_moment();
    if (philo->philo_id % 2 == 0)
        ft_myusleep(1);
    while (existing(philo))
    {
        pick_fork(philo);
        dining(philo);
        sleeping(philo);
    }
    return (data);
}
