/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:26:56 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/15 18:23:32 by tkerroum         ###   ########.fr       */
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
	int				dead_flag;
}				t_data;

typedef struct s_philo
{
	int				philo_id;
	int				times_eaten;
	int				eating;
	size_t			last_meal;
	pthread_t		thread_id;
	pthread_mutex_t	*r_fork_id;
	pthread_mutex_t	*l_fork_id;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
	int				*dead;

	t_data			*data;
}				t_philo;

/*parsing*/
int		parse(int ac, char **av);
int		ft_myatoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		wrong_input(const char *nptr);
int		check_args(int ac, char **av);
t_philo	*initialisation(t_data *data, int ac, char **av);
void    global_routine(t_philo *philo);
int		philos_init(t_philo *philo, t_data *data);
int		mutex_init(t_philo *philo);
void	free_data(t_philo *philo, t_data *data);
void  ft_myusleep(int	moment);
size_t  current_moment();
void	message_update(char *message, t_philo *philo);
void    *philo_routine(void *data);

#endif
