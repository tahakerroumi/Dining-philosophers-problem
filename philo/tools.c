/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:20:59 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/19 17:53:23 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t  current_moment()
{
    struct	timeval var;

	gettimeofday(&var, NULL);
	return ((var.tv_sec * 1000) + (var.tv_usec / 1000));
}

void  ft_myusleep(int	moment, t_philo *philo)
{
    size_t  now;

    now = current_moment();
	while ((current_moment() - now) < moment && existing(philo))
			usleep(250);
	return ;
}

void	message_update(char *message, t_philo *philo)
{
	size_t time;

	pthread_mutex_lock(philo->write_lock);
	time =  current_moment() - philo->start_time;
	if (existing(philo))
		printf("%zu %d %s\n", time, philo->philo_id, message);
	pthread_mutex_unlock(philo->write_lock);
}

int	ft_isdigit(int c)
{
	return (c <= 57 && c >= 48);
}

void	free_data(t_data *data)
{
	int i;

	i = -1;
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	while (++i < data->philos_nbr)
	{
		pthread_mutex_destroy(data->philosophe[i].r_fork_id);
		free(data->philosophe[i].r_fork_id);
	}
}
