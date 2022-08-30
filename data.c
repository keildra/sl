/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:47:13 by ekarali           #+#    #+#             */
/*   Updated: 2022/08/25 19:48:17 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// reads all the lines with get_next_line and splits them into an array
void	read_map(char *filename, t_data *s_info)
{
	char	*lines;
	char	*ret;
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY);
	ret = ft_strdup("");
	lines = get_next_line(fd);
	while (lines)
	{
		if (!s_info)
			return ;
		tmp = ret;
		ret = ft_strjoin(tmp, lines);
		free(lines);
		free(tmp);
		lines = 0;
		lines = get_next_line(fd);
	}
	s_info->map = ft_split(ret, '\n');
	free(ret);
	if (!s_info->map[0])
		error_exit("empty file", NULL);
	close(fd);
}

// checks the map checks it and gets the position of the player
void	get_map_data(t_data *s_info)
{
	int	i;
	int	j;

	check_walls(s_info);
	check_objects(s_info);
	i = -1;
	while (++i < s_info->row)
	{
		j = -1;
		while (++j < s_info->col)
		{
			if (s_info->map[i][j] == 'P')
			{
				s_info->p_pos_y = i;
				s_info->p_pos_x = j;
				check_validity(s_info, i, j, 'E');
			}
			else if (s_info->map[i][j] == 'C')
				check_validity(s_info, i, j, 'P');
		}
	}
	s_info->ball_count = 0;
}

// checks the two vertical and then two horizontal edges of the map
void	check_walls(t_data *s_info)
{
	int	i;

	s_info->row = 0;
	while (s_info->map[s_info->row])
		if (s_info->map[s_info->row++][0] != '1')
			error_exit("there is a problem with the walls", s_info);
	s_info->col = ft_strlen(s_info->map[0]);
	i = -1;
	while (++i < s_info->row)
		if (s_info->map[i][s_info->col - 1] != '1' ||
			ft_strlen(s_info->map[i]) != (size_t)s_info->col)
			error_exit("there is a problem with the walls", s_info);
	i = -1;
	while (s_info->map[0][++i])
		if (s_info->map[0][i] != '1')
			error_exit("there is a problem with the walls", s_info);
	i = -1;
	while (s_info->map[s_info->row - 1][++i])
		if (s_info->map[s_info->row - 1][i] != '1')
			error_exit("there is a problem with the walls", s_info);
}

// checks that the map has 1 P, 1 E, >0 C(s), 1s, 0(s) and nothing else
void	check_objects(t_data *s_info)
{
	int	row;
	int	i;

	s_info->p = 0;
	s_info->e = 0;
	s_info->c = 0;
	row = s_info->row;
	while (row-- > 0)
	{
		i = -1;
		while (++i < s_info->col)
		{
			if (s_info->map[row][i] == 'P')
				s_info->p++;
			else if (s_info->map[row][i] == 'E')
				s_info->e++;
			else if (s_info->map[row][i] == 'C')
				s_info->c++;
			else if (s_info->map[row][i] != '1' && s_info->map[row][i] != '0')
				error_exit("forbidden letter in the map", s_info);
		}
	}
	if (s_info->e <= 0 || s_info->c <= 0 || s_info->p != 1)
		error_exit("too many or too few elements", s_info);
}
