/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:42:45 by ekarali           #+#    #+#             */
/*   Updated: 2022/08/25 17:31:29 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "mlx/mlx.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_data	s_info;

	if (argc != 2)
		error_exit("usage: ./solong [map].ber", NULL);
	if (ft_strncmp(".ber", &argv[1][ft_strlen(argv[1]) - 4], 4))
		error_exit("not a ber file", NULL);
	read_map(argv[1], &s_info);
	get_map_data(&s_info);
	s_info.mlx = mlx_init();
	s_info.win = mlx_new_window(s_info.mlx, (s_info.col) * 64, (s_info.row)
			* 64, "boney");
	get_sprites(&s_info);
	render(&s_info);
	s_info.move_count = 0;
	mlx_hook(s_info.win, 17, (1L << 2), exit_game, &s_info);
	mlx_hook(s_info.win, 2, (1L << 0), ft_key, &s_info);
	mlx_loop(s_info.mlx);
	return (0);
}

// you can test system(leaks so_long); before exit
int	error_exit(char *str, t_data *s_info)
{
	int	i;

	if (s_info)
	{
		i = 0;
		while (s_info->map && s_info->map[i])
			free(s_info->map[i++]);
		free(s_info->map);
	}
	ft_printf("error\n%s\n", str);
	exit(0);
}

int	ft_key(int key, t_data *s_info)
{
	if (key == KEY_W)
		render_move(-1, 0, s_info);
	if (key == KEY_A)
		render_move(0, -1, s_info);
	if (key == KEY_S)
		render_move(1, 0, s_info);
	if (key == KEY_D)
		render_move(0, 1, s_info);
	if (key == KEY_ESC)
		exit_game(s_info);
	return (1);
}

// you can test system(leaks so_long); before exit
int	exit_game(t_data *s_info)
{
	int	i;

	mlx_clear_window(s_info->mlx, s_info->win);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.dog.img);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.ball.img);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.ball_dog.img);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.girl.img);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.grass.img);
	mlx_destroy_image(s_info->mlx, s_info->s_prites.tree.img);
	mlx_destroy_window(s_info->mlx, s_info->win);
	i = 0;
	while (s_info->map && s_info->map[i])
		free(s_info->map[i++]);
	free(s_info->map);
	exit(0);
}
