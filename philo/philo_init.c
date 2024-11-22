/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:47:40 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/22 02:57:20 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_init(t_philo *philo, t_data *data)
{
	int	i;

	if (!philo)
		return (1);
	i = -1;
	while (++i < data->philos_nbr)
	{
		philo[i].data = data;
		philo[i].philo_id = i + 1;
		philo[i].times_eaten = 0;
		philo[i].eating = 0;
		philo[i].dead = &data->dead_flag;
		philo[i].dead_lock = &data->dead_lock;
		philo[i].write_lock = &data->write_lock;
		philo[i].meal_lock = &data->meal_lock;
		philo[i].eat_m_nbr = &data->eat_m_nbr;
		philo[i].eat_meals = &data->eat_meals;
		philo[i].last_meal = current_moment();
		philo[i].start_time = current_moment();
		philo[i].l_fork_id = &data->forks[(i + 1) % data->philos_nbr];
		philo[i].r_fork_id = &data->forks[i];
	}
	return (0);
}

void	fork_init(t_philo *philo, t_data *data)
{
	int	i;

	if (!philo)
		free_data(data);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_nbr);
	if (!data->forks)
	{
		free(philo);
		return ;
	}
	i = -1;
	while (++i < data->philos_nbr)
		pthread_mutex_init(&data->forks[i], NULL);
}

void	mutex_init(t_data *data)
{
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->eat_m_nbr, NULL);
	pthread_mutex_init(&data->eat_meals, NULL);
}

t_philo	*initialisation(t_data *data, int ac, char **av)
{
	t_philo	*philo;

	data->philos_nbr = atoi(av[1]);
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
	data->philosophe = philo;
	mutex_init(data);
	fork_init(philo, data);
	return (philo);
}
