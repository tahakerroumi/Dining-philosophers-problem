/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:08 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/18 04:20:47 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    global_routine(t_data *data)
{
    int         i;
    pthread_t   monitor;

	pthread_create(&monitor, NULL, &monitor_work, data->philosophe);
    i = -1;
    while (++i < data->philos_nbr)
       pthread_create(&data->philosophe[i].thread_id, NULL, &philo_routine, (void *)&data->philosophe[i]);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < data->philos_nbr)
		pthread_join(data->philosophe[i].thread_id, NULL);
}

int main(int ac, char **av)
{
	t_data	data;

    if (parse(ac, av) == -1)
		return (1);
	if (philos_init(initialisation(&data, ac, av), &data))
		return (1);
	global_routine(&data);
	free_data(&data);
	return (0);
}
