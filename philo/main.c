/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:08 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/15 11:40:24 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    global_routine(t_philo *philo)
{
    int i;

    i = -1;
    if (philo[0].data->meals_nbr == 0)
        return ;
    else if (philo[0].data->meals_nbr == 1)
       ; // to do;
    else
    {
        while (++i < philo[0].data->philos_nbr)
        {
            pthread_create(&philo[i].thread_id, NULL, philo_routine, (void *)&philo[i]);
        }
    }
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
	return (0);
}
