/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:01:19 by mku               #+#    #+#             */
/*   Updated: 2025/01/17 16:33:43 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
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
	int		birth_time;
}	t_thread;
//thread.c
void	create_thread(t_thread *thread, t_arg *arg);
void	wait_thread(t_thread *thread, t_arg *arg);
//thread_philo.c
void	fork_eat_sleep(t_thread *thread, t_arg *arg);
//utils.c
void	print_error(char *content);
int		ft_atoi(const char *nptr);
int		gettime(void);
#endif