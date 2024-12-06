/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 05:55:36 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/21 17:42:33 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_finder(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == '%')
		count += ft_putchar('%');
	else if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		count += ft_print_num(va_arg(args, int));
	else if (format == 'u')
		count += ft_un_num(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_print_hexa(va_arg(args, unsigned int), format);
	else if (format == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long), format);
	return (count);
}

int	ft_find_percent(va_list args, const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_format_finder(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;

	result = 0;
	va_start(args, str);
	result = ft_find_percent(args, str);
	va_end(args);
	return (result);
}
