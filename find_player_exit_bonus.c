/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_exit_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:15:49 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 20:15:51 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_find_player(t_cont *cont, int row)
{
	int	j;

	while (row > 0)
	{
		j = 0;
		while (cont->map[row][j])
		{
			if (cont->map[row][j] == 'P')
			{
				cont->player++;
				cont->player_x = j;
				cont->player_y = row;
			}
			j++;
		}
		row--;
	}
}

void	ft_find_exit(t_cont *cont, int row)
{
	int	j;

	while (row > 0)
	{
		j = 0;
		while (cont->map[row][j])
		{
			if (cont->map[row][j] == 'E')
			{
				cont->exit++;
				cont->exit_x = j;
				cont->exit_y = row;
			}
			j++;
		}
		row--;
	}
}

void	ft_find_collectibles(t_cont *cont, int row)
{
	int	j;

	while (row > 0)
	{
		j = 0;
		while (cont->map[row][j])
		{
			if (cont->map[row][j] == 'C')
				cont->collectibles++;
			j++;
		}
		row--;
	}
}

void	ft_find_player_exit(t_cont *cont)
{
	int	row;

	row = cont->rows - 2;
	ft_find_player(cont, row);
	ft_find_exit(cont, row);
	ft_find_collectibles(cont, row);
}
