/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:53:34 by ekarali           #+#    #+#             */
/*   Updated: 2022/08/25 19:53:42 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	find_exit(char **temp, int y, int x, int *r)
{
	if (temp[y][x] == 'E')
	{
		*r = 1;
		return ;
	}	
	if (temp[y][x] != 'E' && temp[y][x] != '1')
		temp[y][x] = '2';
	if (temp[y + 1][x] == '0' || temp[y + 1][x] == 'E' || temp[y + 1][x] == 'C')
		find_exit (temp, y + 1, x, r);
	if (temp[y][x + 1] == '0' || temp[y][x + 1] == 'E' || temp[y][x + 1] == 'C')
		find_exit (temp, y, x + 1, r);
	if (temp[y - 1][x] == '0' || temp[y - 1][x] == 'E' || temp[y - 1][x] == 'C')
		find_exit (temp, y - 1, x, r);
	if (temp[y][x - 1] == '0' || temp[y][x - 1] == 'E' || temp[y][x - 1] == 'C')
		find_exit (temp, y, x - 1, r);
}

void	check_validity(t_data *s_info, int y, int x, char f)
{
	char	**temp;
	int		i;
	int		r;

	temp = malloc(s_info->row * s_info->col + 1);
	i = -1;
	while (++i < s_info->row)
		temp[i] = ft_strdup(s_info->map[i]);
	r = 0;
	if (f == 'E')
		find_exit(temp, y, x, &r);
	if (f == 'P')
		find_player(temp, y, x, &r);
	i = -1;
	while (++i < s_info->row)
		free(temp[i]);
	free(temp);
	if (!r)
		error_exit("the map doesn't have a valid path", s_info);
}

void	find_player(char **temp, int y, int x, int *r)
{
	if (temp[y][x] == 'P')
	{
		*r = 1;
		return ;
	}	
	if (temp[y][x] != 'P' && temp[y][x] != '1')
		temp[y][x] = '2';
	if (temp[y + 1][x] == '0' || temp[y + 1][x] == 'P' || temp[y + 1][x] == 'C')
		find_player (temp, y + 1, x, r);
	if (temp[y][x + 1] == '0' || temp[y][x + 1] == 'P' || temp[y][x + 1] == 'C')
		find_player (temp, y, x + 1, r);
	if (temp[y - 1][x] == '0' || temp[y - 1][x] == 'P' || temp[y - 1][x] == 'C')
		find_player (temp, y - 1, x, r);
	if (temp[y][x - 1] == '0' || temp[y][x - 1] == 'P' || temp[y][x - 1] == 'C')
		find_player(temp, y, x - 1, r);
}
