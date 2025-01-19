/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:46:49 by mku               #+#    #+#             */
/*   Updated: 2025/01/19 19:03:18 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

static void	use_fork(t_arg *arg, t_thread *thread);
static void	done_use_fork(t_arg *arg, t_thread *thread);
static void	eat(t_arg *arg, t_thread *thread);
static void	p_sleep(t_arg *arg, t_thread *thread);

void	fork_eat_sleep(t_thread *thread, t_arg *arg)
{
	if (arg->philo_count == 1)
		return ;
	use_fork(arg, thread);
	eat(arg, thread);
	done_use_fork(arg, thread);
	p_sleep(arg, thread);
}

static void	use_fork(t_arg *arg, t_thread *thread)
{
	int time;

	pthread_mutex_lock(&(arg->fork[thread->left]));
	time = gettime();
	printf("%d %d has taken a fork\n",time - thread->birth_time, thread->id + 1);
	pthread_mutex_lock(&(arg->fork[thread->right]));
	time = gettime();
	printf("%d %d has taken a fork\n",time - thread->birth_time, thread->id + 1);
}

static void	done_use_fork(t_arg *arg, t_thread *thread)
{
	pthread_mutex_unlock(&(arg->fork[thread->right]));
	pthread_mutex_unlock(&(arg->fork[thread->left]));
	usleep(100);
}

static void	eat(t_arg *arg, t_thread *thread)
{
	thread->last_eat = gettime();
	printf("%d %d is eating\n",thread->last_eat - thread->birth_time, thread->id + 1);
	thread->eat_count++;
	usleep(arg->time_to_eat);
}

static void	p_sleep(t_arg *arg, t_thread *thread)
{
	int	time;
	time = gettime();
	printf("%d %d is sleeping\n",time - thread->birth_time, thread->id + 1);
	usleep(arg->time_to_sleep);
}