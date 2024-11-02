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

void	philo_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_nbr)
	{
		data->philo[i].philo_id = i;
		data->philo[i].
	}

}

t_data	*initialisation(int ac, char **av)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philos_nbr = ft_myatoi(av[1]);
	data->die_time = ft_myatoi(av[2]);
	data->eat_time = ft_myatoi(av[3]);
	data->sleep_time = ft_myatoi(av[4]);
	if (ac == 6)
		data->meals_nbr = ft_myatoi(av[5]);
	else
		data->meals_nbr = -1;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->philos_nbr);
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philos_nbr);
	if (!data->philo || !data->fork)
		return (NULL);
	philo_init(data);
}
