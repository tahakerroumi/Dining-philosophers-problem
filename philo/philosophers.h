/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:26:56 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/21 02:51:58 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

struct	s_philo;

typedef struct s_data
{
	int				philos_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meals_nbr;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	struct s_philo	*philosophe;
	int				dead_flag;
	pthread_mutex_t	*forks;
}					t_data;

typedef struct s_philo
{
	int				philo_id;
	int				times_eaten;
	int				eating;
	size_t			last_meal;
	size_t			start_time;
	pthread_t		thread_id;
	pthread_mutex_t	*r_fork_id;
	pthread_mutex_t	*l_fork_id;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
	int				*dead;

	t_data			*data;
}					t_philo;

/*parsing*/
int					parse(int ac, char **av);
int					ft_isdigit(int c);
int					ft_myatoi(const char *nptr);
/*tools*/
t_philo				*initialisation(t_data *data, int ac, char **av);
int					philos_init(t_philo *philo, t_data *data);
void				mutex_init(t_data *data);
void				ft_myusleep(size_t moment, t_philo *philo);
size_t				current_moment(void);
void				message_update(char *message, t_philo *philo);
void				*philo_routine(void *data);
// void				pick_fork(t_philo *philo);
void				dining(t_philo *philo);
// void				sleeping(t_philo *philo);
void				free_data(t_data *data);
int					existing(t_philo *philo);
int					died_checker(t_philo *philo);
int					died(t_philo *philo);
int					all_ate(t_philo *philo);

#endif
