/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:08 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/21 21:36:36 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	global_routine(t_data *data)
{
	int			i;

	i = -1;
	while (++i < data->philos_nbr)
		pthread_create(&data->philosophe[i].thread_id, NULL, philo_routine,
			&data->philosophe[i]);
	while (1)
		if (died(data->philosophe) || all_ate(data->philosophe))
			break ;
	i = -1;
	while (++i < data->philos_nbr)
		pthread_join(data->philosophe[i].thread_id, NULL);
	return ;
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
