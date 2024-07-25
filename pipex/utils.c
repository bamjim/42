/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:16:07 by mku               #+#    #+#             */
/*   Updated: 2024/07/25 22:37:29 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while ((tmp1[i] || tmp2[i]) && i < n)
	{
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start <= len)
		buffer = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (len)
	{
		buffer[i] = s[start];
		i++;
		start++;
		len--;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1length;
	int		s2length;
	int		i;
	char	*buffer;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1length = ft_strlen(s1);
	s2length = ft_strlen(s2);
	i = 0;
	buffer = (char *)malloc((s1length + s2length + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < s1length)
	{
		buffer[i] = s1[i];
		i++;
	}
	while ((i - s1length) < s2length)
	{
		buffer[i] = s2[i - s1length];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

size_t	ft_strlen(const char *s)
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