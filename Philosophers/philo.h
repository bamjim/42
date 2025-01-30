/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:00:21 by mku               #+#    #+#             */
/*   Updated: 2025/01/28 07:38:27 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>

# define DIE 1
# define LIVE 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4

typedef struct s_share
{
	int				die_flag;
	int				total_eat_count;
	pthread_mutex_t	m_share;
	pthread_mutex_t	m_flag;
	pthread_mutex_t	m_print;
}t_share;

typedef struct s_arg
{
	int				argc;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	pthread_mutex_t	*fork;
}t_arg;

typedef struct s_thread
{
	t_share		*share;
	t_arg		*arg;
	int			thread_id;
	int			birth_time;
	int			eat_count;
	int			left_hand;
	int			right_hand;
	int			last_eat;
	int			done_eat;
	pthread_t	thread;
}t_thread;

//init.c
int		init_arg(int argc, char **argv, t_arg *arg);
int		init_thread(t_thread **thread, t_arg *arg, t_share *share);
int		allocate_fork(t_arg *arg);
//utils.c
void	print_error(char *content);
int		ft_atoi(const char *nptr);
int		gettime(void);
void	ft_usleep(int sleep_time);
//thread.c
void	create_thread(t_thread *thread, t_arg *arg);
//work_thread.c
void	*philo_thread(void *thread);
//share_thread.c
void	check_eat_count(t_thread *thread, t_arg *arg);
void	change_die_flag(t_share *share);
//philo_thread.c
int		take_fork(t_thread *thread, t_arg *arg);
void	done_use_fork(t_thread *thread, t_arg *arg);
int		print_stat(t_thread **thread, int type);
#endif