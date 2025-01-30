/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_resource.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:04:38 by mku               #+#    #+#             */
/*   Updated: 2025/01/28 07:06:08 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	add_eat_count(t_share *share);

void	check_eat_count(t_thread *thread, t_arg *arg)
{
	if (arg->argc == 5)
		return ;
	if ((thread->eat_count >= arg->eat_count) && thread->done_eat)
	{
		add_eat_count(thread->share);
		thread->done_eat = 0;
	}
}

static void	add_eat_count(t_share *share)
{
	pthread_mutex_lock(&(share->m_share));
	share->total_eat_count++;
	pthread_mutex_unlock(&(share->m_share));
}

void	change_die_flag(t_share *share)
{
	pthread_mutex_lock(&(share->m_share));
	if (share->die_flag == LIVE)
	{
		pthread_mutex_lock(&(share->m_flag));
		share->die_flag = DIE;
		pthread_mutex_unlock(&(share->m_flag));
	}
	pthread_mutex_unlock(&(share->m_share));
}
