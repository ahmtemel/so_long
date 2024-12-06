/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:43:43 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 18:57:43 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_others(t_cont *cont, int i, int j)
{
	while (i < cont->rows)
	{
		j = 0;
		while (cont->map[i][j])
		{
			if (cont->map[i][j] == '1')
				mlx_put_image_to_window(cont->mlx, cont->win, cont->wall,
					j * 48, i * 48);
			else if (cont->map[i][j] == '0')
				mlx_put_image_to_window(cont->mlx, cont->win, cont->background,
					j * 48, i * 48);
			else if (cont->map[i][j] == 'C')
				mlx_put_image_to_window(cont->mlx, cont->win, cont->collectible,
					j * 48, i * 48);
			j++;
		}
		i++;
	}
}

void	ft_print_player_exit(t_cont *cont)
{
	mlx_put_image_to_window(cont->mlx, cont->win, cont->hero1,
		cont->player_x * 48, cont->player_y * 48);
	mlx_put_image_to_window(cont->mlx, cont->win, cont->exit_img,
		cont->exit_x * 48, cont->exit_y * 48);
}

void	ft_generate_images(t_cont *cont)
{
	ft_print_player_exit(cont);
	ft_print_others(cont, 0, 0);
}

void	ft_xpm_generate(t_cont *cont)
{
	int	x;
	int	y;

	x = 48;
	y = 48;
	cont->background = mlx_xpm_file_to_image(cont->mlx,
			"./textures/grass.xpm", &x, &y);
	cont->exit_img = mlx_xpm_file_to_image(cont->mlx,
			"./textures/gate_xpm.xpm", &x, &y);
	cont->collectible = mlx_xpm_file_to_image(cont->mlx,
			"./textures/coin.xpm", &x, &y);
	cont->wall = mlx_xpm_file_to_image(cont->mlx,
			"./textures/wall.xpm", &x, &y);
	cont->hero1 = mlx_xpm_file_to_image(cont->mlx,
			"./textures/ugly1.xpm", &x, &y);
	ft_generate_images(cont);
}
