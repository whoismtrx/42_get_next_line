/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:00:58 by orekabe           #+#    #+#             */
/*   Updated: 2021/12/30 17:03:22 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_after_new_line(char *str)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!ptr)
		return (NULL);
	while (str[++i])
		ptr[j++] = str[i];
	ptr[j] = '\0';
	free (str);
	return (ptr);
}

char	*get_line(char *str)
{
	char	*ptr;
	int		i;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	char static	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	ret = get_line(str);
	str = get_after_new_line(str);
	return (ret);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd = open("xD.txt", O_RDWR, 777);
// 	char *ret = get_next_line(fd);
// 	char *ret2 = get_next_line(fd);
// 	char *ret3 = get_next_line(fd);
// 	char *ret4 = get_next_line(fd);
// 	printf("%s", ret);
// 	printf("%s", ret2);
// 	printf("%s", ret3);
// 	printf("%s", ret4);
// }