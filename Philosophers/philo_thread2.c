/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:11:18 by mku               #+#    #+#             */
/*   Updated: 2025/01/28 12:49:16 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	odd_use_fork(t_thread *thread, t_arg *arg);
static int	even_use_fork(t_thread *thread, t_arg *arg);

int	take_fork(t_thread *thread, t_arg *arg)
{
	if (thread->thread_id % 2 == 0)
	{
		if (even_use_fork(thread, arg) == DIE)
			return (DIE);
	}
	else
	{
		if (odd_use_fork(thread, arg) == DIE)
			return (DIE);
	}
	return (LIVE);
}

static int	odd_use_fork(t_thread *thread, t_arg *arg)
{
	pthread_mutex_lock(&(arg->fork[thread->left_hand]));
	if (print_stat(&thread, FORK) == DIE)
	{
		pthread_mutex_unlock(&(arg->fork[thread->left_hand]));
		return (DIE);
	}
	if (arg->philo_count == 1)
	{
		pthread_mutex_unlock(&(arg->fork[thread->left_hand]));
		return (DIE);
	}
	pthread_mutex_lock(&(arg->fork[thread->right_hand]));
	if (print_stat(&thread, FORK) == DIE)
	{
		pthread_mutex_unlock(&(arg->fork[thread->left_hand]));
		pthread_mutex_unlock(&(arg->fork[thread->right_hand]));
		return (DIE);
	}
	return (LIVE);
}

static int	even_use_fork(t_thread *thread, t_arg *arg)
{
	pthread_mutex_lock(&(arg->fork[thread->right_hand]));
	if (print_stat(&thread, FORK) == DIE)
	{
		pthread_mutex_unlock(&(arg->fork[thread->right_hand]));
		return (DIE);
	}
	if (arg->philo_count == 1)
	{
		pthread_mutex_unlock(&(arg->fork[thread->right_hand]));
		return (DIE);
	}
	pthread_mutex_lock(&(arg->fork[thread->left_hand]));
	if (print_stat(&thread, FORK) == DIE)
	{
		pthread_mutex_unlock(&(arg->fork[thread->left_hand]));
		pthread_mutex_unlock(&(arg->fork[thread->right_hand]));
		return (DIE);
	}
	return (LIVE);
}

void	done_use_fork(t_thread *thread, t_arg *arg)
{
	pthread_mutex_unlock(&(arg->fork[thread->right_hand]));
	pthread_mutex_unlock(&(arg->fork[thread->left_hand]));
}
