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

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>



int ft_endstr(char *str);

static char    BUFF_SIZE = 5;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*f;
	size_t	i;
	size_t	j;

	i = 0;
	f = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!f)
		return (NULL);
	while (s1[i])
	{
		f[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		f[i] = s2[j];
		i++;
		j++;
	}
	f[i] = '\0';
	return (f);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}


char    *get_next_line(int fd)
{
    char    buf[BUFF_SIZE + 1];
    static char    *str = NULL;
    char    *tmp;
    int     len;

    len = 0;
    if (fd < 0 || BUFF_SIZE < 0)
    {
        return (NULL);
    }
    while ((len = read(fd,buf,BUFF_SIZE) > 0))
    {
        buf[len] = '\0';
        tmp = str;
        str = ft_strjoin(tmp,buf);
        free(tmp);
        if(ft_strchr(str,'\n'))
        {
            break;
        }
    }
    ft_endstr(str);
    return(str);
}

int ft_endstr(char *str)
{
    int i;

    i = 0;
    if (!str)
    {
        return (-1);
    }
    while(str[i] != '\n')
    {
        i++;
    }
    str[i] = '\0';
    return(i);
}

#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
    char    *str = NULL;
	fd = open("hello", O_RDONLY);
	printf("%s",(str = get_next_line(fd)));
}