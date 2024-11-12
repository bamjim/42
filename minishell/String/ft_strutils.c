/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:55:11 by mku               #+#    #+#             */
/*   Updated: 2024/11/12 17:16:48 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int	ft_strncmp(const char *s1, const char *s2, int n);
void	ft_print_fd(char *s, int fd);

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*buffer;
	int		i;
	int		length;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start <= len)
		length = ft_strlen(s) - start + 1;
	else
		length = len + 1;
	buffer = (char *)malloc(length * sizeof(char));
	if (!buffer)
		return (NULL);
	while (len > 0 && s[start] != '\0')
	{
		buffer[i] = s[start];
		i++;
		start++;
		len--;
	}
	buffer[i] = '\0';
	return (buffer);
}

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while ((tmp1[i] || tmp2[i]) && i < n)
	{
		if (tmp1[i] != tmp2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_fd(char *s, int fd)
{
	if (fd < 0 || s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}