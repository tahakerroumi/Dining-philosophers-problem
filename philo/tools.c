/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:20:59 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/17 17:28:56 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	return (c <= 57 && c >= 48);
}

int	wrong_input(const char *nptr)
{
	int		i;

	i = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		i++;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] != '\0')
	{
		ft_putstr_fd("Wrong input!\n" ,2);
		return (1);
	}
	return (0);
}

int check_args(int ac, char **av)
{
	int i;

	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Wrong input!\n" ,2);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		if (wrong_input(av[i]))
			return (1);
		i++;
	}
	return (0);
}

void	free_data(t_data *data)
{
	int i;

	i = -1;
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	while (++i < data->philos_nbr)
	{
		pthread_mutex_destroy(data->philosophe[i].r_fork_id);
		free(data->philosophe[i].r_fork_id);
	}
}
