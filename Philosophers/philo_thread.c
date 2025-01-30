/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:18:06 by mku               #+#    #+#             */
/*   Updated: 2025/01/28 07:38:25 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat_sleep(t_thread *thread, t_arg *arg);
static void	eat_nyam_nyam(t_thread *thread);
static void	print_thinking(t_thread *thread);

void	*philo_thread(void *thread)
{
	t_thread	*_thread;

	_thread = (t_thread *)thread;
	if (_thread->thread_id % 2 == 0)
		usleep(250);
	while (true)
	{
		pthread_mutex_lock(&(_thread->share->m_share));
		if (_thread->share->die_flag == DIE)
		{
			pthread_mutex_unlock(&(_thread->share->m_share));
			break ;
		}
		pthread_mutex_unlock(&(_thread->share->m_share));
		if (eat_sleep(_thread, _thread->arg) == DIE)
			break ;
		pthread_mutex_lock(&(_thread->share->m_share));
		if (_thread->share->die_flag == LIVE)
			print_thinking(_thread);
		pthread_mutex_unlock(&(_thread->share->m_share));
	}
	return (NULL);
}

static int	eat_sleep(t_thread *thread, t_arg *arg)
{
	if (take_fork(thread, arg) == DIE)
		return (DIE);
	if (print_stat(&thread, EAT) == DIE)
	{
		done_use_fork(thread, arg);
		return (DIE);
	}
	done_use_fork(thread, arg);
	if (print_stat(&thread, SLEEP) == DIE)
		return (DIE);
	usleep(150);
	return (LIVE);
}

int	print_stat(t_thread **thread, int type)
{
	pthread_mutex_lock(&((*thread)->share->m_share));
	if ((*thread)->share->die_flag == DIE)
	{
		pthread_mutex_unlock(&((*thread)->share->m_share));
		return (DIE);
	}
	pthread_mutex_unlock(&((*thread)->share->m_share));
	if (type == FORK)
	{
		pthread_mutex_lock(&((*thread)->share->m_print));
		printf("%d %d has taken a fork\n", \
		gettime() - (*thread)->birth_time, (*thread)->thread_id);
		pthread_mutex_unlock(&((*thread)->share->m_print));
	}
	if (type == EAT)
		eat_nyam_nyam(*thread);
	if (type == SLEEP)
	{
		pthread_mutex_lock(&((*thread)->share->m_print));
		printf("%d %d is sleeping\n", gettime() - \
		(*thread)->birth_time, (*thread)->thread_id);
		pthread_mutex_unlock(&((*thread)->share->m_print));
		ft_usleep((*thread)->arg->time_to_sleep);
	}
	return (LIVE);
}

static void	eat_nyam_nyam(t_thread *thread)
{
	pthread_mutex_lock(&(thread->share->m_print));
	printf("%d %d is eating\n", gettime() - \
	thread->birth_time, thread->thread_id);
	pthread_mutex_unlock(&(thread->share->m_print));
	pthread_mutex_lock(&(thread->share->m_share));
	thread->last_eat = gettime();
	thread->eat_count++;
	pthread_mutex_unlock(&(thread->share->m_share));
	check_eat_count(thread, thread->arg);
	ft_usleep(thread->arg->time_to_eat);
}

static void	print_thinking(t_thread *thread)
{
	int	time;

	time = gettime();
	pthread_mutex_lock(&(thread->share->m_print));
	printf("%d %d is thinking\n", time - \
	thread->birth_time, thread->thread_id);
	pthread_mutex_unlock(&(thread->share->m_print));
}
