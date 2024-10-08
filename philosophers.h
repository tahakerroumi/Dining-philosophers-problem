/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum <tkerroum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:26:56 by tkerroum          #+#    #+#             */
/*   Updated: 2024/10/08 15:27:36 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <limits.h>

typedef struct	s_data
{
    int		nop;
	int		ttd;
	int		tte;
	int		tts;
	int		nom;
}				t_data;

/*parsing*/
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		wrong_input(const char *nptr);
int		check_args(int ac, char **av);
size_t	ft_strlen(const char *s);

#endif