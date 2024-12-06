/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:15:34 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 20:15:36 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_right(t_cont *cont)
{
	ft_exit_control(cont, cont->player_y, (cont->player_x + 1));
	ft_control_player_x(cont->player_y, (cont->player_x + 1), +1,
		cont);
}

void	ft_handle_left(t_cont *cont)
{
	ft_exit_control(cont, cont->player_y, (cont->player_x - 1));
	ft_control_player_x(cont->player_y, (cont->player_x - 1), -1,
		cont);
}

void	ft_handle_down(t_cont *cont)
{
	ft_exit_control(cont, (cont->player_y + 1), cont->player_x);
	ft_control_player_y((cont->player_y + 1), cont->player_x, +1,
		cont);
}

void	ft_handle_up(t_cont *cont)
{
	ft_exit_control(cont, (cont->player_y - 1), cont->player_x);
	ft_control_player_y((cont->player_y - 1), cont->player_x, -1,
		cont);
}

int	ft_handle_keys(int code, t_cont *cont)
{
	if (code == 53)
		ft_exit(cont);
	if (code == 13)
	{
		ft_handle_up(cont);
	}
	if (code == 1)
	{
		ft_handle_down(cont);
	}
	if (code == 0)
	{
		ft_handle_left(cont);
	}
	if (code == 2)
	{
		ft_handle_right(cont);
	}
	return (0);
}
