/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:27:04 by mku               #+#    #+#             */
/*   Updated: 2025/01/17 16:33:11 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

static void *ph_thread(void *thread);

void	create_thread(t_thread *thread, t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_count)
	{
		pthread_create(thread[i].thread, NULL, ph_thread, (void *)&thread[i]);
		i++;
	}
}

void	wait_thread(t_thread *thread, t_arg *arg)
{
	for (int i = 0 ; i < arg->philo_count; i ++)
		pthread_join(*(thread[i].thread), NULL);
}
static void *ph_thread(void *thread)
{
	t_thread *_thread;

	_thread = (t_thread *)thread;
	_thread->birth_time = gettime();
	if (_thread->id % 2 == 0)
		usleep(150);
	while (1)
	{
		fork_eat_sleep(_thread, _thread->arg);
		int time = gettime();
		printf("%d %d is thinking\n",time - _thread->birth_time, _thread->id);
		usleep(100);
	}
}