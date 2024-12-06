/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:15:23 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/25 20:15:25 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rectangle(t_cont *cont, int len, int i)
{
	if (i == 0)
		cont->rectangle = len;
	else if (len != cont->rectangle)
	{
		cont->rectangle = -1;
		ft_printf("Map isn't rectangle\n");
		exit(1);
	}
}

void	ft_allocate_memory(t_cont *cont)
{
	cont->map = (char **)malloc(cont->rows * sizeof(char *));
	cont->t_map = (char **)malloc(cont->rows * sizeof(char *));
}

void	ft_convert(t_cont *cont, int sd)
{
	cont->string = get_next_line(sd);
	if (cont->string != 0)
	{
		cont->map[cont->m_i] = (char *)malloc(cont->rectangle);
		cont->t_map[cont->m_i] = (char *)malloc(cont->rectangle);
		cont->m_j = 0;
		while (cont->string[cont->m_j] && cont->string[cont->m_j] != '\n')
		{
			cont->map[cont->m_i][cont->m_j] = cont->string[cont->m_j];
			cont->t_map[cont->m_i][cont->m_j] = cont->string[cont->m_j];
			cont->m_j++;
		}
		cont->map[cont->m_i][cont->m_j] = '\0';
		cont->t_map[cont->m_i][cont->m_j] = '\0';
		cont->m_i++;
	}
	else
		cont->control = 1;
	free(cont->string);
}

void	ft_matrix(t_cont *cont, int sd)
{
	ft_allocate_memory(cont);
	while (cont->control != 1)
		ft_convert(cont, sd);
}

void	ft_read_map(t_cont *cont, int fd)
{
	char	*c;
	int		i;
	int		j;
	int		len;
	int		control;

	i = 0;
	control = 0;
	len = 0;
	while (control != 1)
	{
		j = 0;
		c = get_next_line(fd);
		if (c != 0)
		{
			cont->rows++;
			while (c[j] && c[j++] != '\n')
				len = j;
			ft_check_rectangle(cont, len, i);
			i++;
		}
		else
			control = 1;
		free(c);
	}
}
