/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:26:56 by tkerroum          #+#    #+#             */
/*   Updated: 2024/11/24 07:21:36 by tkerroum         ###   ########.fr       */
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
	int				philos_nbr; 		// pnumber of philosphers
	int				die_time;			// time to die, every philosopher should eat sleep and think i a less time than time to die else he die's
	int				eat_time;			// duration of eating process
	int				sleep_time; 		// duration of sleeping process
	int				meals_nbr;			// number of meals that every philosopher should eat
	struct s_philo	*philosophe;		// pointer struct of philosphers
	pthread_mutex_t	*forks;				// forks array depends on how many philosophers i have n my program
	pthread_mutex_t	times_eaten_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	int				dead_flag;
}					t_data;

typedef struct s_philo
{
	int				philo_id; 			// the id of the philosopher
	int				times_eaten;		// variable to calculate how many times the philosopher has eaten
	int				*dead;				// pointer to the dead flag to derefrence it if any philo died so i can break the monitor loop and end the simulation
	size_t			last_meal;			// to store the last time each philo's last meal and calculate it with time to die to check if he's gonna die fro starvation or not
	size_t			start_time; 		// to store the tie the program has starten and print each event andthe moment it happend
	pthread_t		thread_id; 			// pthread_create takes it as input to create a thread
	pthread_mutex_t	*r_fork_id; 		// mutex for the right fork
	pthread_mutex_t	*l_fork_id; 		// mutex for the left fork
	pthread_mutex_t	*write_lock;		// mutex to prevent data race in printing messages
	pthread_mutex_t	*last_meal_lock;	// mutex to prevent data race during storing the time the philo has eaten
	pthread_mutex_t	*dead_lock; 		// mutex to prevent data race when  modifyin the dead flag if any philosopher died
	pthread_mutex_t	*times_eaten_lock; 	// mutex to prevent data race during incrementing the times eating variable for each each so after we can check if all philos ate the number of meals provided
	pthread_mutex_t	*first_fork; 		// to fix potentional deadlock error
	pthread_mutex_t	*second_fork; 		// to fix potentional deadlock error
	t_data			*data; 				// pointer to data structure
}					t_philo;

/*parsing*/
int					parse(int ac, char **av);
int					ft_isdigit(int c);
int					ft_myatoi(const char *nptr);
/*initialization*/
t_philo				*initialisation(t_data *data, int ac, char **av);
int					philos_init(t_philo *philo, t_data *data);
void				mutex_init(t_data *data);
/*tools*/
void				message_update(char *message, t_philo *philo);
void				ft_myusleep(size_t moment, t_philo *philo);
size_t				current_moment(void);
void				free_data(t_data *data);
/*simulation*/
void				*philo_routine(void *data);
int					existing(t_philo *philo);
int					died(t_philo *philo);
int					all_ate(t_philo *philo);

#endif
