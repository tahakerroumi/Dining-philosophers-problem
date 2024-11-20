/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:08 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/20 18:14:46 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*one_philo(void	*data)
{
	t_philo *philo = (t_philo *)data;

	pthread_mutex_lock(philo->r_fork_id);
	message_update("has taken a fork", philo);
	ft_myusleep(philo->data->die_time, philo);
	pthread_mutex_unlock(philo->r_fork_id);
	return (data);
}

void	global_routine(t_data *data)
{
	int			i;
	pthread_t	monitor;

	if (!(data->philos_nbr))
		return ;
	pthread_create(&monitor, NULL, &monitor_work, data->philosophe);
	if (data->philos_nbr == 1)
	{
		pthread_create(&data->philosophe[0].thread_id, NULL, &one_philo, (void *)&data->philosophe[0]);
		pthread_join(data->philosophe[0].thread_id, NULL);
		pthread_join(monitor, NULL);
		return ;
	}
	i = -1;
	while (++i < data->philos_nbr)
		pthread_create(&data->philosophe[i].thread_id, NULL, &philo_routine,
			(void *)&data->philosophe[i]);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < data->philos_nbr)
		pthread_join(data->philosophe[i].thread_id, NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parse(ac, av) == -1)
		return (1);
	if (philos_init(initialisation(&data, ac, av), &data))
		return (free_data(&data), 1);
	global_routine(&data);
	free_data(&data);
	free(data.philosophe);
	free(data.forks);
	return (0);
}
