/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:07:26 by mku               #+#    #+#             */
/*   Updated: 2024/11/15 17:52:30 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define PATH_MAX 1024

# define COMPLETE 1
# define FAIL_TO_FIND_CMD 0
typedef struct s_tokken_list	t_tokken_list,t_envlist,t_grammer_list;

//change_directory
int		change_directory(t_tokken_list *list, t_envlist *envlist);
char	*find_home_dir(t_envlist *envlist);
void	change_oldpwd(t_envlist *envlist, char *path);
void	change_pwd(t_envlist *envlist, char *path);
//print_env
int		check_env(t_tokken_list *tokken, t_envlist *envlist);
//pwd
int	check_pwd(t_tokken_list *tokken, t_envlist *envlist);
void	print_env(t_envlist *envlist);
//export
typedef struct s_stat t_stat;
int	export(t_tokken_list *tokken, t_stat *stat);

#endif