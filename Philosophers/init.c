/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:00:06 by mku               #+#    #+#             */
/*   Updated: 2025/01/28 12:49:11 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_share(t_share *share);

int	init_arg(int argc, char **argv, t_arg *arg)
{
	if (argc != 5 && argc != 6)
		return (1);
	arg->argc = argc;
	arg->philo_count = atoi(argv[1]);
	if (arg->philo_count <= 0)
		return (1);
	arg->time_to_die = atoi(argv[2]);
	if (arg->time_to_die <= 0)
		return (1);
	arg->time_to_eat = atoi(argv[3]);
	if (arg->time_to_eat <= 0)
		return (1);
	arg->time_to_sleep = atoi(argv[4]);
	if (arg->time_to_sleep <= 0)
		return (1);
	if (argc == 6)
	{
		arg->eat_count = atoi(argv[5]);
		if (arg->eat_count <= 0)
			return (1);
	}
	else
		arg->eat_count = -1;
	return (0);
}

int	allocate_fork(t_arg *arg)
{
	arg->fork = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * arg->philo_count);
	if (arg->fork == NULL)
	{
		printf("fork_allocate_error\n");
		return (1);
	}
	return (0);
}

int	init_thread(t_thread **thread, t_arg *arg, t_share *share)
{
	int		i;

	*thread = (t_thread *)malloc(sizeof(t_thread) * arg->philo_count);
	if (*thread == NULL)
		return (1);
	init_share(share);
	i = 0;
	while (i < arg->philo_count)
	{
		(*thread)[i].arg = arg;
		(*thread)[i].left_hand = i;
		(*thread)[i].right_hand = (i + 1) % arg->philo_count;
		(*thread)[i].thread_id = i + 1;
		(*thread)[i].eat_count = 0;
		(*thread)[i].done_eat = 1;
		(*thread)[i].share = share;
		(*thread)[i].thread = 0;
		i++;
	}
	return (0);
}

static void	init_share(t_share *share)
{
	share->die_flag = LIVE;
	share->total_eat_count = 0;
	pthread_mutex_init(&(share->m_print), NULL);
	pthread_mutex_init(&(share->m_share), NULL);
	pthread_mutex_init(&(share->m_flag), NULL);
}
