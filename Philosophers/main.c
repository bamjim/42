/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:59:44 by mku               #+#    #+#             */
/*   Updated: 2025/01/28 07:16:21 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutex(t_thread *thread, t_arg *arg);
static void	free_allocate(t_thread *thread, t_arg *arg);
static void	init_fork(t_arg *arg);

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_thread	*thread;
	t_share		share;

	if (init_arg(argc, argv, &arg))
	{
		printf("arg error\n");
		return (1);
	}
	if (allocate_fork(&arg))
		return (1);
	if (init_thread(&thread, &arg, &share))
	{
		printf("allocate error\n");
		return (1);
	}
	init_fork(&arg);
	create_thread(thread, &arg);
	destroy_mutex(thread, &arg);
	free_allocate(thread, &arg);
}

static void	destroy_mutex(t_thread *thread, t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_count)
	{
		pthread_mutex_destroy(&(arg->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(thread->share->m_share));
	pthread_mutex_destroy(&(thread->share->m_print));
	pthread_mutex_destroy(&(thread->share->m_flag));
}

static void	free_allocate(t_thread *thread, t_arg *arg)
{
	free((arg->fork));
	free(thread);
}

static void	init_fork(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_count)
	{
		pthread_mutex_init(&(arg->fork[i]), NULL);
		i++;
	}
}
