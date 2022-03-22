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
#include <stdio.h>

char    *get_next_line(int fd)
{
    char    buf[BUFFER_SIZE + 1];
    static  char    *str = NULL;
    static	char    *tmp = NULL;
    int     len;

    len = 0;
    if (fd < 0 || BUFFER_SIZE < 0)
    {
        return (NULL);
    }
    while ((len = read(fd,buf,BUFFER_SIZE) > 0))
    {
        buf[len] = '\0';
        tmp = buf;
        str = ft_strjoin(str,tmp);
        free(tmp);
        if(ft_strchr(str,'\n'))
        {
            break;
        }
    }
    return(str);
}

int		main(int argc, char **argv)
{
	int		fd;
    char    *str = NULL;
	fd = open("hello", O_RDONLY);
	while(*str)
	{
		printf("%s",(str = get_next_line(fd)));
	}
}