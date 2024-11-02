/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ta7ino <ta7ino@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 16:47:40 by ta7ino            #+#    #+#             */
/*   Updated: 2024-10-28 16:47:40 by ta7ino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philos_init(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_nbr)
	{
		philo[i].data = data;
		philo[i].philo_id = i + 1;
		philo[i].times_eaten = 0;
		philo[i].l_fork_id = philo[(i + 1) % data->philos_nbr].r_fork_id;
	}
}

int	fork_init(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philos_nbr);
	if (!data->fork)
		return (1);
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
	t_philo *philo;

	data->philos_nbr = ft_myatoi(av[1]);
	data->die_time = ft_myatoi(av[2]);
	data->eat_time = ft_myatoi(av[3]);
	data->sleep_time = ft_myatoi(av[4]);
	if (ac == 6)
		data->meals_nbr = ft_myatoi(av[5]);
	else
		data->meals_nbr = -1;
	philo = malloc(sizeof(t_philo) * data->philos_nbr);
	if (!philo || fork_init(philo, data))
		return (1);
	philos_init(philo, data);
}
