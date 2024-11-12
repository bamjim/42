/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:50:39 by mku               #+#    #+#             */
/*   Updated: 2024/11/12 19:08:59 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <readline/readline.h>
//#include <readline/history.h>
#include <signal.h>
#include <stdio.h>
//#include "Tree/tree.h"
#include <stdlib.h>
//#include "minishell.h"
#include "List/list.h"
#include "String/ft_string.h"

t_envlist *get_envlist(char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_envlist *envlist;

	envlist = get_envlist(envp);

	char * line = "cmd1 || cmd2 && cmd3";

}

t_envlist *get_envlist(char **envp)
{
	t_envlist *envlist;
	int	i;

	i = 0;
	envlist = (t_envlist *)malloc(sizeof(t_envlist));
	envlist->head = NULL;
	envlist->tail = NULL;
	while (envp[i] != NULL)
	{
		lst_push_back(envlist, envp[i], T_ENV);
		i++;
	}
	return (envlist);
}