/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:08 by tkerroum          #+#    #+#             */
/*   Updated: 2024/10/08 15:09:50 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '0' || str[i] == '+')
		i++;
	if (ft_strlen(str + i) > ft_strlen("2147483647"))
	{
		ft_putstr_fd("Wrong input!\n" ,2);
		return (1);
	}
	return (0);
}

int parse(int ac, char **av)
{
	int	i;

	i = 1;
	if (check_args(ac, av))
		return (1);
	while (av[i])
	{
		if (check_num(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
    if (parse(ac, av))
		return (1);
	return (0);
}