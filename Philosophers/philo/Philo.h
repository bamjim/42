/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:01:19 by mku               #+#    #+#             */
/*   Updated: 2025/01/14 15:16:38 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_arg
{
	int philo_count;
	int time_to_eat;
	int time_to_die;
	int time_to_sleep;
	int eat_count;
	pthread_mutex_t *fork;
}	t_arg;

typedef struct s_thread
{
	t_arg *arg;
	pthread_t *thread;
	int		id;
	int		eat_count;
	int		left;
	int		right;

}	t_thread;

void	print_error(char *content);
int		ft_atoi(const char *nptr);
#endif