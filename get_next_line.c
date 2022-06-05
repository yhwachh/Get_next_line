/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:51:14 by ibalbako          #+#    #+#             */
/*   Updated: 2022/03/21 10:51:16 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_and_free(char *save, char *buf)
{
	char	*temp;

	temp = ft_strjoin(save, buf);
	free(save);
	return (temp);
}

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
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
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
		i++;
	i = i + 2;
	line = ft_calloc(i , sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}
	
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buf;
	int			len;

	if (!save)
		save = ft_calloc(1, 1);
	buf = ft_test(fd);
	len = 1;
	while (len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		buf[len] = 0;
		save = ft_join_and_free(save, buf);
		if (ft_strchr(buf, '\n'))
			break;
	}
	free(buf);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_next_line(save);
	return (line);
}

char	*ft_test(int fd)
{
	char *buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	return (buf);
}