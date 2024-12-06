/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 06:32:58 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/11/11 11:25:04 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_un_num(unsigned int num)
{
	long	nbr;
	int		count;
	char	*str;

	count = 0;
	nbr = (long)num;
	str = ft_itoa(nbr);
	count += ft_print_str(str);
	free(str);
	return (count);
}
