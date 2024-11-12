/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:20:59 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/12 22:09:41 by tkerroum         ###   ########.fr       */
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

void	free_data(t_philo *philo, t_data *data)
{
	int i;

	i = -1;
	if (!philo)
		return ;
	while (++i < data->philos_nbr)
		if (philo[i].r_fork_id != NULL)
			free(philo[i].r_fork_id);
	if (philo[0].write_lock)
		free(philo[0].write_lock);
	if (philo[0].meal_lock)
		free(philo[0].meal_lock);
	if (philo[0].dead_lock)
		free(philo[0].dead_lock);
	if (philo)
		free (philo);
}
