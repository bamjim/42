/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:56:41 by mku               #+#    #+#             */
/*   Updated: 2024/06/12 18:59:11 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

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

char	*map_read(int fd, char *buffer)
{
	char	*temp;
	char	*delete_temp;
	int		read_size;

	if (buffer == NULL)
		return (NULL);
	temp = NULL;
	while (1)
	{
		read_size = read(fd, buffer, READ_BUFFERSIZE);
		buffer[read_size] = '\0';
		if (read_size == 0)
		{
			free(buffer);
			return (temp);
		}
		if (temp == NULL)
			temp = ft_strdup("");
		delete_temp = temp;
		temp = ft_strjoin(temp, buffer);
		free(delete_temp);
	}
	return (temp);
}

char	*map_set(char *dir)
{
	char	*buffer;
	char	*map;
	int		i;
	int		pos_count;
	int		fd;

	pos_count = 0;
	i = 0;
	fd = open(dir, O_RDONLY);
	if (fd <= 0)
		fdf_error("NO SUCH FILE");
	buffer = (char *)malloc(sizeof(char) * READ_BUFFERSIZE);
	if (buffer == NULL)
		free(buffer);
	map = map_read(fd, buffer);
	close(fd);
	return (map);
}
