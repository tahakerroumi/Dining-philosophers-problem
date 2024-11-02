/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ta7ino <ta7ino@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 18:09:22 by ta7ino            #+#    #+#             */
/*   Updated: 2024-10-18 18:09:22 by ta7ino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_myatoi(const char *nptr)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13) \
	|| (nptr[i] == '+') || (nptr[i] == '0'))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		if (res > INT_MAX)
		{
			ft_putstr_fd("Wrong input!\n" ,2);
			return (-1);
		}
		i++;
	}
	return (res);
}

int parse(int ac, char **av)
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