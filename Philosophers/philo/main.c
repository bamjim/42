/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:40:14 by mku               #+#    #+#             */
/*   Updated: 2025/01/17 16:34:11 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void init_arg(t_arg *arg, t_thread **thread, char **argv);
void	init_thread(t_arg *arg, t_thread **thread);

int main(int argc, char **argv)
{
	t_arg arg;
	t_thread *thread;

	if (argc != 5 && argc != 6)
		print_error("wrong arg");
	init_arg(&arg, &thread, argv);
	init_thread(&arg, &thread);
	create_thread(thread, &arg);
	wait_thread(thread, &arg);
	return (0);

}



void init_arg(t_arg *arg, t_thread **thread, char **argv)
{
	t_arg *_arg;
	int		i;

	i = 0;
	_arg = arg;
	_arg->philo_count = ft_atoi(argv[1]);
	_arg->time_to_die = ft_atoi(argv[2]) * 1000;
	_arg->time_to_eat = ft_atoi(argv[3]) * 1000;
	_arg->time_to_sleep = ft_atoi(argv[4]) * 1000;
	_arg->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * arg->philo_count);
	if (_arg->fork == NULL)
		print_error("mallocate error\n");
	if (argv[5] != NULL)
		_arg->eat_count = ft_atoi(argv[5]);
	while (i < arg->philo_count)
	{
		pthread_mutex_init(&(_arg->fork[i]), NULL);
		i++;
	}

}

void	init_thread(t_arg *arg, t_thread **thread)
{
	int	i;

	i = 0;
	*thread = (t_thread *)malloc(sizeof(t_thread) * arg->philo_count);
	if (*thread == NULL)
		print_error("mallocate error\n");
	while (i < arg->philo_count)
	{
		(*thread)[i].arg = arg;
		(*thread)[i].id = i;
		(*thread)[i].eat_count = 0;
		(*thread)[i].left = i;
		(*thread)[i].right = (i + 1) % arg->philo_count;
		(*thread)[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		if (*thread == NULL)
		print_error("mallocate error\n");
		i++;
	}
}
