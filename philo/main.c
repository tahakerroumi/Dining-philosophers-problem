/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ta7ino <ta7ino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:08 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/04 21:27:58 by ta7ino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

    if (parse(ac, av) == -1)
		return (1);
	philo = initialisation(&data, ac, av);
	if (!philo)
		// free data and stuuf
	global_routine(&data, philo);
	return (0);
}
