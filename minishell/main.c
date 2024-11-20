/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:02:13 by seojang           #+#    #+#             */
/*   Updated: 2024/11/20 15:01:52 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"
#include "./builtin/builtin.h"
#include "./Signal/ft_signal.h"

void	loop_prompt(char *line ,char **envp, t_stat *stat);

void	get_envlist(char **envp, t_envlist **envlist)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
			ft_lstadd_back(envlist, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
}

void	get_grammer_list(t_grammer_list **g_list)
{

	ft_lstadd_back(g_list, ft_lstnew("|"));
	ft_lstadd_back(g_list, ft_lstnew("("));
	ft_lstadd_back(g_list, ft_lstnew(")"));
	ft_lstadd_back(g_list, ft_lstnew("<"));
	ft_lstadd_back(g_list, ft_lstnew(">"));
	ft_lstadd_back(g_list, ft_lstnew("<<"));
	ft_lstadd_back(g_list, ft_lstnew(">>"));
}

int main(int ac, char **av, char **envp)
{
	char	*line;
	char	*temp;
	t_envlist	*envlist;
	t_stat	stat;
	t_grammer_list *g_list;

	envlist = NULL;
	g_list = NULL;
	get_grammer_list(&g_list);
	get_envlist(envp, &envlist);
	stat.envlist = envlist;
	stat.grammer_list = g_list;
	line = NULL;
	(void)ac;
	(void)av;
	loop_prompt(line, envp, &stat);
	return (0);
}

void	loop_prompt(char *line ,char **envp, t_stat *stat)
{
	while (TRUE)
	{
		sig_echo_ctl_off();
		line = readline("minishell^~^ :");
		if (!ft_strlen(line))
			continue ;
		if (line)
		{
			ft_tokenizer(line, envp, stat);
			free(line);
			line = NULL;
		}
	}
}