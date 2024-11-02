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
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct	s_data
{
	int				philos_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meals_nbr;
	size_t			start_time;
	size_t			current_time;
	pthread_mutex_t	*fork;
}				t_data;
 
typedef struct s_philo
{
	int				philo_id;
	int				times_eaten;
	size_t			last_meal;
	pthread_t		thread_id;
	pthread_mutex_t	*l_fork_id;
	pthread_mutex_t	*r_fork_id;
	t_data			*data;
}				t_philo;


/*parsing*/
int		parse(int ac, char **av);
int		ft_myatoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		wrong_input(const char *nptr);
int		check_args(int ac, char **av);
t_data	*initialisation(int ac, char **av);

#endif
