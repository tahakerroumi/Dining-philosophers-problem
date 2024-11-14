/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:47 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/14 01:53:53 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    sleeping(t_philo *philo)
{
    // print is sleeping
    ft_myusleep(philo->data->sleep_time);
}

void    pick_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork_id);
    printf("");
    pthread_mutex_unlock(philo->r_fork_id);
}

void    priority_waiting(t_philo *philo)
{
    if (philo->philo_id % 2 == 0 || philo->philo_id != (philo->data->philos_nbr - 1))
        ft_myusleep(77777);
    else
        return ;
}

void    *philo_routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    priority_waiting(philo);
    // lock forks
    // eat
    // sleep
}

void    global_routine(t_philo *philo)
{
    int i;

    i = -1;
    if (philo[0].data->meals_nbr == 0)
        return ;
    else if (philo[0].data->meals_nbr == 1)
       ; // to do;
    else
    {
        while (++i < philo[0].data->philos_nbr)
        {
            pthread_create(&philo[i].thread_id, NULL, philo_routine, (void *)&philo[i]);
        }
    }
}