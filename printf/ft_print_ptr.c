/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 06:41:53 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/11/11 11:27:43 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long ptr, char format)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_print_hexa(ptr, format);
	return (count);
}
