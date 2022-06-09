/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:51:56 by ibalbako          #+#    #+#             */
/*   Updated: 2022/06/09 15:21:31 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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
	//free (s1);
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
