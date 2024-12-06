/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 06:45:13 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/11/11 09:00:21 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

void	norm_killer(unsigned long value, char format)
{
	if (format == 'X')
	{
		if (value > 9)
			ft_putchar((int)value + 55);
		else
			ft_putchar((int)value + 48);
	}
	else
	{
		if (value > 9)
			ft_putchar((int)value + 55 + 32);
		else
			ft_putchar((int)value + 48);
	}
}

int	ft_print_hexa(unsigned long value, char format)
{
	int	count;

	count = 0;
	if (value == 0)
		return (write(1, "0", 1));
	if (value >= 16)
	{
		ft_print_hexa(value / 16, format);
		ft_print_hexa(value % 16, format);
	}
	else
		norm_killer(value, format);
	count += ft_hex_len(value);
	return (count);
}
