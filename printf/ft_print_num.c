/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 06:18:22 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/11/11 07:23:42 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int num)
{
	long	nbr;
	char	*str;
	int		count;

	nbr = num;
	str = ft_itoa(num);
	count = ft_print_str(str);
	free(str);
	return (count);
}
