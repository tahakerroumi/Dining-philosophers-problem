/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:08 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/15 21:13:26 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	died_checker(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (((current_moment() - philo->last_meal) >= philo->data->die_time) && philo->eating = 0)
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
	while (++i < philo[0].data->philos_nbr)
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
		if (died(philo) == 1|| all_ate(philo) == 1)
			break ;
	}
	return (data);
}

void    global_routine(t_philo *philo)
{
    int         i;
    pthread_t   monitor;

	pthread_create(&monitor, NULL, monitor_work, philo);
    i = -1;
    while (++i < philo[0].data->philos_nbr)
        pthread_create(&philo[i].thread_id, NULL, philo_routine, (void *)&philo[i]);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < philo[0].data->philos_nbr)
		pthread_join(philo[i].thread_id, NULL);
}

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(philo->write_lock);
	pthread_mutex_destroy(philo->dead_lock);
	pthread_mutex_destroy(philo->meal_lock);
	while (++i < philo[0].data->philos_nbr)
		pthread_mutex_destroy(philo[i].r_fork_id);
}

int main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

    if (parse(ac, av) == -1)
		return (1);
	philo = initialisation(&data, ac, av);
	if (!philo || !philos_init(philo, &data))
		free_data(philo, &data);
	global_routine(philo);
	destroy_mutex(philo);
	return (0);
}
