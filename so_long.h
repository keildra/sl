/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 03:13:16 by ekarali           #+#    #+#             */
/*   Updated: 2022/08/25 19:48:30 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_images
{
	void	*img;
	int		w;
	int		h;
}			t_images;

typedef struct s_prite
{
	t_images	dog;
	t_images	ball_dog;
	t_images	ball;
	t_images	girl;
	t_images	tree;
	t_images	grass;
}				t_prite;

typedef struct s_data
{
	int		row;
	int		col;
	int		e;
	int		c;
	int		p;
	int		move_count;
	int		ball_count;
	int		p_pos_y;
	int		p_pos_x;
	void	*mlx;
	void	*win;
	char	**map;
	t_prite	s_prites;
}			t_data;

// main.c
void	run(t_data *s_info);
int		error_exit(char *str, t_data *s_info);
int		ft_key(int key, t_data *s_info);
int		exit_game(t_data *s_info);
// data.c
void	read_map(char *filename, t_data *s_info);
void	get_map_data(t_data *s_info);
void	check_walls(t_data *s_info);
void	check_objects(t_data *s_info);
// render.c
void	get_sprites(t_data *s_info);
void	render(t_data *s_info);
void	render_dog(t_data *s_info, int x, int y);
void	render_move(int m_x, int m_y, t_data *s_info);
// valid.c
void	find_exit(char **temp, int y, int x, int *r);
void	find_player(char **temp, int y, int x, int *r);
void	check_validity(t_data *s_info, int y, int x, char f);

#endif
