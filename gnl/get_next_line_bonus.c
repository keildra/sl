/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:42:06 by ekarali           #+#    #+#             */
/*   Updated: 2022/02/03 20:58:56 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*readline(char *sline, int fd)
{
	int		bytes;
	char	*buffer;
	char	*temp;

	bytes = 1;
	if (!sline)
		sline = ft_strdup("");
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes && !ft_strchr(sline, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			break ;
		buffer[bytes] = '\0';
		temp = sline;
		sline = ft_strjoin(sline, buffer);
		free(temp);
	}
	free(buffer);
	return (sline);
}

char	*get_next_line(int fd)
{
	static char	*sl[1024];
	char		*output;
	char		*tmp;

	sl[fd] = readline(sl[fd], fd);
	if (!sl[fd])
		return (NULL);
	if (ft_strchr(sl[fd], '\n'))
		output = ft_substr(sl[fd], 0, ft_strchr(sl[fd], '\n') - sl[fd] + 1);
	else
		output = ft_strdup(sl[fd]);
	if (output && output[0] == 0)
	{
		free(output);
		output = 0;
		free(sl[fd]);
		sl[fd] = 0;
		return (NULL);
	}
	tmp = sl[fd];
	sl[fd] = ft_substr(tmp, ft_strchr(tmp, '\n') - tmp + 1, ft_strlen(tmp));
	free (tmp);
	return (output);
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*str;

	// char *test = ft_strdup("");
	// printf("uuuuuuuuuuuuuuuuu((%s))", test);
	// if (!test)
	// 	printf("ohnoooooooooooooooooooooo");
	fd = open("text", O_RDONLY);
	str = get_next_line(fd);
	printf("1:<%s>", str);
	free(str);
	str = get_next_line(fd);
	printf("2:<%s>", str);
	free(str);
	str = get_next_line(fd);
	printf("3:<%s>", str);
	free(str);
	str = get_next_line(fd);
	printf("4:<%s>", str);
	free(str);
	str = get_next_line(fd);
	printf("5:<%s>", str);
	free(str);
	str = get_next_line(fd);
	printf("6:<%s>", str);
	free(str);
	close(fd);
}
*/