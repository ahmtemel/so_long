/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:14:33 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 20:14:36 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_last_column(t_cont *cont)
{
	int	i;

	i = 0;
	while (cont->map[cont->rows - 1][i])
	{
		if (cont->map[cont->rows - 1][i] == '1' && cont->x == 1)
			i++;
		else
		{
			cont->x = -1;
			break ;
		}
	}
}

void	ft_side_walls(t_cont *cont)
{
	int	i;

	i = cont->rows -2;
	while (i > 0)
	{
		if (cont->y == 1 && cont->map[i][0] == '1'
				&& cont->map[i][cont->rectangle - 1] == '1')
			i--;
		else
		{
			cont->y = -1;
			break ;
		}
	}
}

void	ft_first_column(t_cont *cont)
{
	int	i;

	i = 0;
	while (cont->map[0][i])
	{
		if (cont->x == 1 && cont->map[0][i] == '1')
			i++;
		else
		{
			cont->x = -1;
			break ;
		}
	}
}

void	ft_check_walls(t_cont *cont)
{
	ft_first_column(cont);
	ft_side_walls(cont);
	ft_last_column(cont);
}
