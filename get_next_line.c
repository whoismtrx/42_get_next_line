/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:00:58 by orekabe           #+#    #+#             */
/*   Updated: 2021/12/29 22:51:53 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	ch;

	if (!s)
		return (NULL);
	i = 0;
	ch = (char)c;
	if (c == 0)
		return (s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == ch)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_read(char *ret, int fd)
{
	char	*ptr;
	int		rd;

	rd = 1;
	ptr = malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	while (!ft_strchr(ret, '\n') && rd > 0)
	{
		rd = read(fd, ptr, BUFFER_SIZE);
		if (rd < 0)
		{
			free (ptr);
			return (NULL);
		}
		ptr[rd] = '\0';
		ret = ft_strjoin(ret, ptr);
	}
	free (ptr);
	return (ret);
}
char *get_next_line(int fd)
{
	char static *str;
	// char *ptr;
	char *ret;
	
	ret = get_next_line(fd);
	return (ret);
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("fd", O_CREAT | O_RDWR, 777);
	char *ret = get_next_line(fd);
	printf("%s", ret);
}