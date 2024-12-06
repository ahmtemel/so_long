/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:13:40 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 20:30:41 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_zero(t_cont *cont)
{
	cont->x = 1;
	cont->y = 1;
	cont->exit = 0;
	cont->rectangle = 0;
	cont->collectibles = 0;
	cont->count = 0;
	cont->rows = 0;
	cont->player_x = -1;
	cont->player_y = -1;
	cont->exit_x = 0;
	cont->exit_y = 0;
	cont->m_i = 0;
	cont->m_j = 0;
	cont->control = 0;
	cont->player = 0;
	cont->path = 1;
	cont->different = 1;
	cont->step = 0;
}

void	ft_error_check(t_cont *cont)
{
	if (cont->x == -1 || cont->y == -1)
		ft_printf("There's a hole in the wall\n");
	if (cont->collectibles == 0)
		ft_printf("There is no collectibles\n");
	if (cont->exit != 1)
	{
		if (cont->exit == 0)
			ft_printf("There is no exit\n");
		if (cont->exit > 1)
			ft_printf("There is more than 1 exit");
	}
	if (cont->player != 1)
	{
		if (cont->player == 0)
			ft_printf("There is no player\n");
		if (cont->player > 1)
			ft_printf("There is more than 1 player\n");
	}
	if (cont->different == -1)
		ft_printf("The map contains only P C E 1 0 ");
	if (cont->different == 1 && cont->path != 1)
		ft_printf("There is no valid path\n");
}

void	ft_map_functions(t_cont *cont, int fd, int sd)
{
	ft_read_map(cont, fd);
	close(fd);
	if (cont->rectangle != -1)
		ft_matrix(cont, sd);
	close(sd);
	if (cont->rectangle != -1)
	{
		ft_check_walls(cont);
		ft_find_player_exit(cont);
		ft_valid_different(cont);
		ft_error_check(cont);
	}
	ft_error_exit(cont);
}

void	ft_game_functions(t_cont *cont)
{
	cont->mlx = mlx_init();
	cont->win = mlx_new_window(cont->mlx, (cont->rectangle * 48),
			(cont->rows * 48), "Nox");
	ft_xpm_generate(cont);
	mlx_hook(cont->win, 2, 0, ft_handle_keys, cont);
	mlx_hook(cont->win, 17, 0, ft_exit, cont);
	mlx_loop(cont->mlx);
}

int	main(int ac, char **av)
{
	int				fd;
	int				sd;
	t_cont			cont;

	if (ac != 2)
	{
		ft_printf("Must be 2 arguments");
		exit(1);
	}
	fd = open(av[1], O_RDWR);
	sd = open(av[1], O_RDWR);
	if (fd == -1)
	{
		ft_printf("File error");
		exit(1);
	}
	ft_zero(&cont);
	ft_map_functions(&cont, fd, sd);
	ft_game_functions(&cont);
}
