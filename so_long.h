/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:14:53 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 20:14:55 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"
# include "./printf/ft_printf.h"

typedef struct s_controler
{
	void	*mlx;
	void	*win;
	void	*hero1;
	void	*hero2;
	void	*hero3;
	void	*wall;
	void	*background;
	void	*exit_img;
	void	*collectible;
	int		control;
	char	*string;
	int		m_i;
	int		m_j;
	char	**map;
	char	**t_map;
	int		x;
	int		y;
	int		exit;
	int		rectangle;
	int		collectibles;
	int		count;
	int		rows;
	int		player;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		path;
	int		different;
	int		step;
}			t_cont;

void	ft_read_map(t_cont *map, int fd);
void	ft_check_rectangle(t_cont *cont, int len, int i);
void	ft_check_walls(t_cont *cont);
void	ft_read_map(t_cont *cont, int fd);
void	ft_matrix(t_cont *cont, int sd);
void	ft_find_player_exit(t_cont *cont);
void	ft_error_check(t_cont *cont);
void	ft_valid_different(t_cont *cont);
void	ft_check_valid_path_t(t_cont *cont, int x, int y);
void	ft_check_valid_path(t_cont *cont, int a, int b);
void	ft_generate_images(t_cont *checker);
void	ft_xpm_generate(t_cont *cont);
int		ft_exit(t_cont *cont);
int		ft_handle_keys(int code, t_cont *cont);
void	ft_control_player_y(int player_y, int player_x, int indicator,
			t_cont *cont);
void	ft_control_player_x(int player_y, int player_x, int indicator,
			t_cont *cont);
void	ft_exit_control(t_cont *cont, int player_y, int player_x);
void	ft_error_exit(t_cont *cont);
#endif
