/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:03:29 by mku               #+#    #+#             */
/*   Updated: 2025/01/31 00:44:50 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		monitor_thread(t_thread *thread, t_arg *arg);
static int		check_philo_die(t_thread *thread, t_arg *arg);
static int		check_total_eat(t_thread *thread, t_arg *arg);
static void		wait_thread(t_thread *thread, t_arg *arg);

void	create_thread(t_thread *thread, t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_count)
	{
		thread[i].birth_time = gettime();
		thread[i].last_eat = thread[i].birth_time;
		pthread_create(&(thread[i].thread), NULL, \
		philo_thread, (void *)&(thread[i]));
		i++;
	}
	monitor_thread(thread, arg);
	wait_thread(thread, arg);
}

static void	monitor_thread(t_thread *thread, t_arg *arg)
{
	while (1)
	{
		if (check_philo_die(thread, arg))
			break ;
		if (arg->argc == 6 && check_total_eat(thread, arg))
			break ;
	}
}

static int	check_philo_die(t_thread *thread, t_arg *arg)
{
	int		i;
	t_share	*share;

	share = thread->share;
	i = 0;
	while (i < arg->philo_count)
	{
		pthread_mutex_lock(&(share->m_share));
		if (gettime() - thread[i].last_eat >= arg->time_to_die)
		{
			pthread_mutex_unlock(&(thread->share->m_share));
			change_die_flag(share);
			pthread_mutex_lock(&(share->m_print));
			usleep(200);
			printf("%d %d is die\n", \
			gettime() - thread->birth_time, thread->thread_id);
			pthread_mutex_unlock(&(share->m_print));
			return (1);
		}
		pthread_mutex_unlock(&(share->m_share));
		i++;
	}
	return (0);
}

static int	check_total_eat(t_thread *thread, t_arg *arg)
{
	int		i;
	t_share	*share;

	share = thread->share;
	i = 0;
	while (i < arg->philo_count)
	{
		pthread_mutex_lock(&(share->m_share));
		if (share->total_eat_count >= arg->philo_count)
		{
			share->die_flag = DIE;
			pthread_mutex_unlock(&(share->m_share));
			return (1);
		}
		pthread_mutex_unlock(&(share->m_share));
		i++;
	}
	return (0);
}

static void	wait_thread(t_thread *thread, t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_count)
	{
		pthread_join(thread[i].thread, NULL);
		i++;
	}
}
