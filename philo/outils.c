/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:14:05 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/14 01:58:58 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t  current_moment()
{
    struct	timeval var;

	gettimeofday(&var, NULL);
	return ((var.tv_sec * 1000) + (var.tv_sec / 1000));
}

void  ft_myusleep(int	moment)
{
    size_t  now;

    now = current_moment();
	while (current_moment() - now < moment)
		usleep(777);
}
void	message_update(char *message, t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	printf("[%zu]", current_moment() - );
}