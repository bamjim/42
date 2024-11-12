/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:16:43 by mku               #+#    #+#             */
/*   Updated: 2024/11/12 19:01:57 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_DLESS,
	T_DGREAT,
	T_LESS,
	T_GREAT,
	T_LPAREN,
	T_RPAREN,
	T_AND_IF,
	T_OR_IF,
	T_ERROR,
	T_EOF,
	T_ENV
}	t_token_type;

typedef struct s_node
{
	t_token_type type;
	char *content;
	struct s_node *next;
	struct s_node *prev;
}t_node;

typedef struct s_list
{
	int	count;
	t_node *head;
	t_node *tail;
}t_list, t_envlist, t_tokenlist;


void	print_list(t_list *list);
void	lst_push_back(t_list *list, char *content, t_token_type type);
void	lst_delete(t_list *list, char *content);
void	lst_push_front(t_list *list, char *content, t_token_type type);
t_node*	lst_find_content(t_list *list, char *content);
#endif