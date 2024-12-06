/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:15:53 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 20:15:55 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_exit(t_cont *cont)
{
	if (cont->x == -1 || cont->y -1 || cont->collectibles == 0
		|| cont->exit != 1 || cont->player != 1)
		exit(0);
	if (cont->different == -1 || cont->path != 1)
		exit(0);
}
