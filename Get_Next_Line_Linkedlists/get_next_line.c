/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:00:58 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/06 20:25:08 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_after_new_line(char *str)
{
	char *ptr;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!ptr)
		return (NULL);
	while (str[++i])
		ptr[j++] = str[i];
	ptr[j] = '\0';
	free(str);
	return (ptr);
}

char *get_line(char *str)
{
	char *ptr;
	int i;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 2));
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

t_list *ft_lstnew(char *content, int fd)
{
	t_list *new;

	// if (!content)
	// {
	// 	content = (char *)malloc(sizeof(char));
	// 	*content = '\0';
	// }
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->rest = content;
	new->file = fd;
	new->next = NULL;
	return (new);
}

char *get_next_line(int fd)
{
	static t_list *str;
	char *ret;

	if (!str)
		str = ft_lstnew(NULL, fd);
	else
		str = ft_lstnew(str->rest, fd);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str->rest = ft_read(str->rest, fd);
	if (!str->rest)
		return (NULL);
	ret = get_line(str->rest);
	str->rest = get_after_new_line(str->rest);
	if (str->rest)
	{
		free(str->rest);
		free(str);
		str = NULL;
	}
	return (ret);
}

// #include <fcntl.h>
// int main()
// {
// 	int fd = open("xD.txt", O_RDWR, 777);
// 	char *ret;
// 	while ((ret = get_next_line(fd)))
// 	{
// 		printf("%s", ret);
// 		free (ret);	
// 	}
// 	printf("%s", ret);
// 	free (ret);
// 	close(fd);
// }