/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:49:11 by ekarali           #+#    #+#             */
/*   Updated: 2022/08/25 19:44:47 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "printf/ft_printf.h"
#include "mlx/mlx.h"

void	destroy_sprites(t_data *s_info, int i)
{
	if (i == 0)
		error_exit("couldn't find the required xpm files", s_info);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.dog.img);
	if (i == 1)
		error_exit("couldn't find the required xpm files", s_info);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.ball_dog.img);
	if (i == 2)
		error_exit("couldn't find the required xpm files", s_info);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.ball.img);
	if (i == 3)
		error_exit("couldn't find the required xpm files", s_info);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.girl.img);
	if (i == 4)
		error_exit("couldn't find the required xpm files", s_info);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.tree.img);
	if (i == 5)
		error_exit("couldn't find the required xpm files", s_info);
}

void	get_sprites(t_data *map)
{
	map->s_prites.dog.img = mlx_xpm_file_to_image(map->mlx,
			"s/dog.xpm", &map->s_prites.dog.w, &map->s_prites.dog.h);
	if (!map->s_prites.dog.img)
		destroy_sprites(map, 0);
	map->s_prites.ball_dog.img = mlx_xpm_file_to_image(map->mlx,
			"s/ball_dog.xpm", &map->s_prites.ball_dog.w,
			&map->s_prites.ball_dog.h);
	if (!map->s_prites.ball_dog.img)
		destroy_sprites(map, 0);
	map->s_prites.ball.img = mlx_xpm_file_to_image(map->mlx, "s/ball.xpm",
			&map->s_prites.ball.w, &map->s_prites.ball.h);
	if (!map->s_prites.ball.img)
		destroy_sprites(map, 2);
	map->s_prites.girl.img = mlx_xpm_file_to_image(map->mlx, "s/girl.xpm",
			&map->s_prites.girl.w, &map->s_prites.girl.h);
	if (!map->s_prites.girl.img)
		destroy_sprites(map, 3);
	map->s_prites.tree.img = mlx_xpm_file_to_image(map->mlx, "s/tree.xpm",
			&map->s_prites.tree.w, &map->s_prites.tree.h);
	if (!map->s_prites.tree.img)
		destroy_sprites(map, 4);
	map->s_prites.grass.img = mlx_xpm_file_to_image(map->mlx, "s/grass.xpm",
			&map->s_prites.grass.w, &map->s_prites.grass.h);
	if (!map->s_prites.grass.img)
		destroy_sprites(map, 5);
}

void	render(t_data *s_info)
{
	int	x;
	int	y;

	x = -1;
	while (++x < s_info->row)
	{
		y = -1;
		while (++y < s_info->col)
		{
			mlx_put_image_to_window(s_info->mlx, s_info->win,
				s_info->s_prites.grass.img, y * 64, x * 64);
			if (s_info->map[x][y] == '1')
				mlx_put_image_to_window(s_info->mlx, s_info->win,
					s_info->s_prites.tree.img, y * 64, x * 64);
			else if (s_info->map[x][y] == 'C')
				mlx_put_image_to_window(s_info->mlx, s_info->win,
					s_info->s_prites.ball.img, y * 64, x * 64);
			else if (s_info->map[x][y] == 'E')
				mlx_put_image_to_window(s_info->mlx, s_info->win,
					s_info->s_prites.girl.img, y * 64, x * 64);
			else if (s_info->map[x][y] == 'P')
				render_dog(s_info, x, y);
		}
	}
}

void	render_dog(t_data *s_info, int x, int y)
{
	if (s_info->ball_count == 0)
		mlx_put_image_to_window(s_info->mlx, s_info->win,
			s_info->s_prites.dog.img, y * 64, x * 64);
	else if (s_info->ball_count > 0)
		mlx_put_image_to_window(s_info->mlx, s_info->win,
			s_info->s_prites.ball_dog.img, y * 64, x * 64);
}

void	render_move(int m_y, int m_x, t_data *s_info)
{
	if (s_info->map[s_info->p_pos_y + m_y][s_info->p_pos_x + m_x] == '1')
		return ;
	else if (s_info->map[s_info->p_pos_y + m_y][s_info->p_pos_x + m_x] == 'C')
		s_info->ball_count++;
	else if (s_info->map[s_info->p_pos_y + m_y][s_info->p_pos_x + m_x] == 'E')
	{
		if (s_info->c == s_info->ball_count)
		{
			ft_printf("move count: %d\n", ++s_info->move_count);
			exit_game(s_info);
		}
		else
			return ;
	}
	s_info->map[s_info->p_pos_y][s_info->p_pos_x] = '0';
	s_info->p_pos_y += m_y;
	s_info->p_pos_x += m_x;
	s_info->map[s_info->p_pos_y][s_info->p_pos_x] = 'P';
	ft_printf("move count: %d\n", ++s_info->move_count);
	mlx_clear_window(s_info->mlx, s_info->win);
	render(s_info);
}
