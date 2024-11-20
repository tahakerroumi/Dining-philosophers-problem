/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:09:22 by ta7ino            #+#    #+#             */
/*   Updated: 2024/11/20 00:34:22 by tkerroum         ###   ########.fr       */
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

int	wrong_input(const char *nptr)
{
	int	i;

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
		ft_putstr_fd("Wrong input!\n", 2);
		return (1);
	}
	return (0);
}

int	ft_myatoi(const char *nptr)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13)
		|| (nptr[i] == '+') || (nptr[i] == '0'))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		if (res > INT_MAX)
		{
			ft_putstr_fd("Wrong input!\n", 2);
			return (-1);
		}
		i++;
	}
	return (res);
}

int	check_args(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Wrong input!\n", 2);
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

int	parse(int ac, char **av)
{
	int	i;

	i = 1;
	if (check_args(ac, av))
		return (-1);
	while (av[i])
	{
		if (ft_myatoi(av[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
