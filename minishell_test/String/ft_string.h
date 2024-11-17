/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:50:55 by mku               #+#    #+#             */
/*   Updated: 2024/11/12 17:01:16 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

char	*ft_substr(char const *s, unsigned int start, int len);
int	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int	ft_strncmp(const char *s1, const char *s2, int n);//true = 1 flase = 0
void	ft_print_fd(char *s, int fd);
#endif
