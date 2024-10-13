/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:26:56 by tkerroum          #+#    #+#             */
/*   Updated: 2024/10/10 02:54:48 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <limits.h>

typedef struct	s_data
{
	int		philos_nbr; /*number of philos*/
	int		die_time; /*time to die*/
	int		eat_time; /*time to eat*/
	int		sleep_time; /*time to sleep*/
	int		meals_nbr; /*number of meals*/
	
}				t_data;

/*parsing*/
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		wrong_input(const char *nptr);
int		check_args(int ac, char **av);
size_t	ft_strlen(const char *s);

#endif