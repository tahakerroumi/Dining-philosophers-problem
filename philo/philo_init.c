/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:47:40 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/15 21:14:04 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	mutex_init(t_philo *philo)
{
	int	i;

	philo[0].write_lock = malloc(sizeof(pthread_mutex_t));
	philo[0].meal_lock = malloc(sizeof(pthread_mutex_t));
	philo[0].dead_lock = malloc(sizeof(pthread_mutex_t));
	if (!philo[0].write_lock || !philo[0].meal_lock || !philo[0].dead_lock)
		return (1);
	if (pthread_mutex_init(philo[0].write_lock, NULL) || \
		pthread_mutex_init(philo[0].meal_lock, NULL) || pthread_mutex_init(philo[0].dead_lock, NULL))
		return (1);
	i = 0;
	while (++i < philo[0].data->philos_nbr)
	{
		philo[i].write_lock = philo[0].write_lock;
		philo[i].meal_lock = philo[0].meal_lock;
		philo[i].dead_lock = philo[0].dead_lock;
	}
	return (0);
}

int	philos_init(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_nbr)
	{
		philo[i].data = data;
		philo[i].philo_id = i + 1;
		philo[i].times_eaten = 0;
		philo[i].eating = 0;
		philo[i].l_fork_id = philo[(i + 1) % philo->data->philos_nbr].r_fork_id;
	}
	if (mutex_init(philo))
		return (1);
	return (0);
}

int	fork_init(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_nbr)
	{
		philo[i].r_fork_id = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].r_fork_id || pthread_mutex_init(philo[i].r_fork_id, NULL))
			return (1);
	}
	return (0);
}

t_philo	*initialisation(t_data *data, int ac, char **av)
{
	t_philo	*philo;

	data->philos_nbr = ft_myatoi(av[1]);
	data->die_time = ft_myatoi(av[2]);
	data->eat_time = ft_myatoi(av[3]);
	data->sleep_time = ft_myatoi(av[4]);
	data->dead_flag = 0;
	if (ac == 6)
		data->meals_nbr = ft_myatoi(av[5]);
	else
		data->meals_nbr = -1;
	philo = malloc(sizeof(t_philo) * data->philos_nbr);
	if (!philo)
		return (NULL);
	if (fork_init(philo, data))
		return (NULL);
	return (philo);
}
