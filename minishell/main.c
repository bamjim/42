/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:02:13 by seojang           #+#    #+#             */
/*   Updated: 2024/11/17 18:18:51 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"
#include "./builtin/builtin.h"
#include "./Signal/ft_signal.h"

void	handler(int sig)
{
	if (sig != SIGINT)
		return ;
	write(1, "minishell>^C\n", 13);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

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
	//signal(SIGINT, new_line);
	while (1)
	{
		new_promot();
		line = readline("minishell^~^ :");
		if (!ft_strlen(line))
			continue ;
		if (line)
		{
			ft_tokenizer(line, envp, &stat);
			free(line);
			line = NULL;
		}
	}
	return (0);
}

//#include <stdio.h>
//#include "ms_test.h"
//int main(int argc, char ** argv, char ** envp)
//{
//	//t_envlist	*envlist;
//	//envlist = NULL;
//	//get_envlist(envp, &envlist);
//	int index = 0;
//	(void)argc;
//	(void)argv;
//	char *str = ft_double_qoute_check("\"hello world\"", &index, 0);
//	printf("%s\n", str);
//	//printf("hello");
//	return (0);
//}