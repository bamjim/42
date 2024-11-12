/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:56:01 by mku               #+#    #+#             */
/*   Updated: 2024/11/12 18:57:07 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//typedef enum e_node_type
//{
//	N_CMD,
//	N_AND,
//	N_OR,
//	N_PIPE,
//	N_SUBSHELL,
//	N_INPUT,
//	N_OUTPUT,
//	N_HERE_DOC,
//	N_APPEND
//}	t_node_type;
typedef struct s_list t_list, t_envlist, t_tokenlist;

typedef struct s_stat
{
	t_envlist *envlist;
	t_tokenlist *tokenlist;
}t_stat;
#endif