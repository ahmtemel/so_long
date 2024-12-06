/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_different_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:14:46 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 20:14:48 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_valid_path_t_map(t_cont *cont, int x, int y)
{
	if (cont->t_map[y][x] != '1' && cont->t_map[y][x]
		&& cont->t_map[y][x] != '.' && cont->t_map[y][x] != 'E')
	{
		cont->t_map[y][x] = '.';
		ft_check_valid_path(cont, x, y);
	}
}

void	ft_check_valid_path(t_cont *cont, int a, int b)
{
	int	x;
	int	y;

	x = a;
	y = b;
	ft_check_valid_path_t_map(cont, x, y);
	ft_check_valid_path_t_map(cont, (x + 1), y);
	ft_check_valid_path_t_map(cont, x, y + 1);
	ft_check_valid_path_t_map(cont, x - 1, y);
	ft_check_valid_path_t_map(cont, x, y - 1);
}

void	ft_check_tmap(t_cont *cont)
{
	int	i;
	int	j;

	i = 1;
	while (i < cont->rows)
	{
		j = 0;
		while (cont->t_map[i][j])
		{
			if (cont->t_map[i][j] == 'C' && cont->path == 1)
				cont->path = -1;
			j++;
		}
		i++;
	}
	if (cont->t_map[cont->exit_y][cont->exit_x - 1] != '.'
		&& cont->t_map[cont->exit_y][cont->exit_x + 1] != '.'
		&& cont->t_map[cont->exit_y + 1][cont->exit_x] != '.'
		&& cont->t_map[cont->exit_y - 1][cont->exit_x] != '.')
		cont->path = -1;
}

void	ft_check_different(t_cont *cont)
{
	int	i;
	int	j;

	i = 0;
	while (i < cont->rows)
	{
		j = 0;
		while (cont->map[i][j])
		{
			if (cont->map[i][j] != 'C' && cont->map[i][j] != 'P'
				&& cont->map[i][j] != '1' && cont->map[i][j] != '0'
				&& cont->map[i][j] != 'E')
				cont->different = -1;
			j++;
		}
		i++;
	}
}

void	ft_valid_different(t_cont *cont)
{
	ft_check_different(cont);
	if (cont->different == 1)
	{
		ft_check_valid_path(cont, cont->player_x, cont->player_y);
		ft_check_tmap(cont);
	}
}
