/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:19:05 by mku               #+#    #+#             */
/*   Updated: 2024/08/07 17:36:03 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_all
{
	int		pid;
	int		pid2;
	char	*cmd;
	char	*cmd2;
	char	*sl_cmd;
	char	*sl_cmd2;
	char	**sp_cmd;
	char	**sp_cmd2;
	char	*path;
	char	*path2;
	char	**path_split;
}	t_all;

//pipex.c
void	error(char *a);
//pipex_utils.c
void	set_all(char *cmd, char *cmd2, t_all *all);
void	find_path(char **envp, t_all *all);
char	*init_path(t_all *all, int i, char *ls_cmd, char *cmd);
void	free_var(t_all *all);
//utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif