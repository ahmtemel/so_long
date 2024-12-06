/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:15:08 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 20:15:10 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_control(t_cont *cont, int player_y, int player_x)
{
	if (cont->map[player_y][player_x] == 'E' && cont->collectibles == 0)
	{
		cont->step++;
		ft_exit(cont);
	}
}

void	ft_control_player_y(int player_y, int player_x, int indicator,
		t_cont *cont)
{
	if (cont->map[player_y][player_x] == '0'
		|| cont->map[player_y][player_x] == 'C')
	{
		cont->step++;
		ft_printf("Current move is %d\n", cont->step);
		if (cont->map[player_y][player_x] == 'C')
			cont->collectibles--;
		cont->map[player_y][player_x] = 'P';
		cont->map[cont->player_y][cont->player_x] = '0';
		cont->player_y += indicator;
		ft_generate_images(cont);
	}
}

void	ft_control_player_x(int player_y, int player_x, int indicator,
		t_cont *cont)
{
	if (cont->map[player_y][player_x] == '0'
		|| cont->map[player_y][player_x] == 'C')
	{
		cont->step++;
		ft_printf("Current move is %d\n", cont->step);
		if (cont->map[player_y][player_x] == 'C')
			cont->collectibles--;
		cont->map[player_y][player_x] = 'P';
		cont->map[cont->player_y][cont->player_x] = '0';
		cont->player_x += indicator;
		ft_generate_images(cont);
	}
}

int	ft_exit(t_cont *cont)
{
	mlx_destroy_window(cont->mlx, cont->win);
	ft_printf("Game over at step %d\n", cont->step);
	exit(0);
	return (0);
}
