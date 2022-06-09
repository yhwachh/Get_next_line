/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:51:14 by ibalbako          #+#    #+#             */
/*   Updated: 2022/06/09 15:15:53 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if(!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *str)
{
	int		len;
	char	*temp;

	len = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	while (len != 0)
	{
		len = read(fd, temp, BUFFER_SIZE);
		if (len == -1)
		{
			free (temp);
			return (0);
		}
		temp[len] = '\0';
		str = ft_strjoin(str, temp);
		if (ft_strchr(str, '\n'))
		{
			free (temp);
			return (str);
		}
	}
	free (temp);
	return (str);
}
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_next_line(save);
	return (line);
}