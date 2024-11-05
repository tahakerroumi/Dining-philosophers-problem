/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ta7ino <ta7ino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:47 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/04 22:54:21 by ta7ino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    fork_locking(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork_id);
    
}

void    *philo_routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    // lock forks
    // eat
    // sleep
}

void    global_routine(t_data *data, t_philo *philo)
{
    int i;

    i = -1;
    if (data->meals_nbr == 0)
        return ;
    else if (data->meals_nbr == 1)
        // to do
    else
    {
        while (++i < data->philos_nbr)
        {
            pthread_create(&philo[i].thread_id, NULL, philo_routine, (void *)&philo[i]);
        }
    }
}