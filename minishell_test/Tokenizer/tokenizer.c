/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:14:59 by mku               #+#    #+#             */
/*   Updated: 2024/11/18 20:09:32 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../String/ft_string.h"
#include "../minishell.h"
#include "../List/list.h"

void	tokenizer(char *line, t_stat *stat)
{
	int	start;
	int	end;

	end = 0;
	start = end;
	while (line[end] != 0)
	{
		while (line[end] == ' ')
			end++;
		if (line[end] == ' ' && line[end + 1] != '|')
		{
			lst_push_back(stat->tokenlist, ft_substr(line, start, end - start), T_WORD);
			start = end;
		}
		else if (line[end] == '|')
		{
			while (line[start] == ' ')
				start++;
			lst_push_back(stat->tokenlist, ft_substr(line, start, end - start), T_WORD);
			end++;
			start = end;
			lst_push_back(stat->tokenlist, ft_strdup("|"), T_PIPE);
		}
		end++;
	}
	if (start < end)
		lst_push_back(stat->tokenlist, ft_substr(line, start, end - start), T_WORD);
}
