/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:32:35 by ekarali           #+#    #+#             */
/*   Updated: 2022/02/03 20:37:54 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../printf/ft_printf.h"

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
	{
		ft_printf("malloc error");
		return (NULL);
	}
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
	static char	*sl;
	char		*output;
	char		*tmp;

	sl = readline(sl, fd);
	if (!sl)
		return (NULL);
	if (ft_strchr(sl, '\n'))
		output = ft_substr(sl, 0, ft_strchr(sl, '\n') - sl + 1);
	else
		output = ft_strdup(sl);
	if (output && output[0] == 0)
	{
		free(output);
		output = 0;
		free(sl);
		sl = 0;
		return (NULL);
	}
	tmp = sl;
	sl = ft_substr(tmp, ft_strchr(tmp, '\n') - tmp + 1, ft_strlen(tmp));
	free (tmp);
	return (output);
}
